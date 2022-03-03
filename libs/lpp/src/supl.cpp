#include "supl.h"
#include "asn_helper.h"
#include "internal_lpp.h"
#include "tcp.h"

void supl_session_create(SUPLSession* session, uint32_t ip) {
    int _supl_session_id = 1;
    session->id          = _supl_session_id++;
    session->slp_size    = 0;
    session->slp_buffer  = NULL;  // TODO(ewasjon): Leak
    memcpy(session->ip, &ip, sizeof(uint32_t));
}

int supl_session_harvest(SUPLSession* session, ULP_PDU_t* ulp) {
    if (session->slp_buffer || session->slp_size > 0)
        return 1;

    session->slp_buffer = 0;
    session->slp_size   = 0;

    void* buffer;
    int   result = uper_encode_to_new_buffer(
        &asn_DEF_SlpSessionID, 0, (void*)ulp->sessionID.slpSessionID, &buffer);
    if (result == -1)
        return 0;

    session->slp_buffer = (char*)buffer;
    session->slp_size   = result;

    return 1;
}

// Helper function for creating a SUPL message.
ULP_PDU_t* supl_create_message(SUPLSession* session, UlpMessage_PR present) {
    ULP_PDU_t* ulp       = ALLOC_ZERO(ULP_PDU_t);
    ulp->length          = 0;
    ulp->version.maj     = 2;
    ulp->version.min     = 1;
    ulp->version.servind = 0;

    SetSessionID_t* session_id                 = ALLOC_ZERO(SetSessionID_t);
    session_id->sessionId                      = session->id;
    session_id->setId.present                  = SETId_PR_iPAddress;
    session_id->setId.choice.iPAddress.present = IPAddress_PR_ipv4Address;
    OCTET_STRING_fromBuf(&session_id->setId.choice.iPAddress.choice.ipv4Address,
                         (const char*)session->ip, 4);
    ulp->sessionID.setSessionID = session_id;
    ulp->sessionID.slpSessionID = OPTIONAL_MISSING;

    // Trick to copy the slp session from previous SUPL messages, by decoding
    // the encoded slp buffer.
    if (session->slp_size > 0) {
        SlpSessionID_t** slp = &ulp->sessionID.slpSessionID;
        uper_decode_complete(0, &asn_DEF_SlpSessionID, (void**)slp,
                             session->slp_buffer, session->slp_size);
    }

    ulp->message.present = present;
    return ulp;
}

void supl_free_message(ULP_PDU_t* ulp) {
    ASN_STRUCT_FREE(asn_DEF_ULP_PDU, ulp);
}

// Helper function to send a SUPL message.
int supl_send_pdu(TCPClient* client, ULP_PDU_t* ulp) {
    char buffer[1 << 16];
    memset(buffer, 0, sizeof(buffer));

    // Encode without length
    asn_enc_rval_t ret = uper_encode_to_buffer(&asn_DEF_ULP_PDU, NULL, ulp,
                                               buffer, sizeof(buffer));
    if (ret.encoded == -1) {
        return 0;
    }

    // Encode with length
    ulp->length = (ret.encoded + 7) >> 3;
    ret         = uper_encode_to_buffer(&asn_DEF_ULP_PDU, NULL, ulp, buffer,
                                sizeof(buffer));
    if (ret.encoded < 0) {
        return 0;
    }

    // The length should not have changed!
    if (ulp->length != (ret.encoded + 7) >> 3) {
        return 0;
    }

    int bytes = tcp_client_send(client, buffer, ulp->length);
    if (bytes != ulp->length)
        return 0;

    return 1;
}

// Helper to read SUPL messages
int supl_read(TCPClient* client, ULP_PDU_t* pdu, int milliseconds) {
    char buffer[1 << 16];

    int bytes =
        tcp_client_receive(client, buffer, sizeof(buffer), milliseconds);
    if (bytes == 0)
        return 0;
    if (bytes <= 0) {
        return 0;
    }

    int size = bytes;
    // NOTE: Some SUPL messages are very big, e.g. supl.google.com SUPLPOS with
    // ephemeris. This means that sometimes the 'buffer' will not contain the
    // whole message but only apart of it. This means we need to wait for the
    // rest of the data. Try to decode the message and if it failed with
    // RC_WMORE wait for more data and try again.
    asn_dec_rval_t rval =
        uper_decode_complete(0, &asn_DEF_ULP_PDU, (void**)&pdu, buffer, bytes);
    if (rval.code == RC_FAIL) {
        return 0;
    }

    int expected_size = pdu->length;
    assert((size_t)expected_size < sizeof(buffer));
    if (rval.code == RC_WMORE) {
        while (size < expected_size) {
            bytes = tcp_client_receive(client, buffer + size,
                                       expected_size - size, -1);
            if (bytes <= 0) {
                return 0;
            }

            size += bytes;
        }

        asn_dec_rval_t rval = uper_decode_complete(0, &asn_DEF_ULP_PDU,
                                                   (void**)&pdu, buffer, size);
        if (rval.code != RC_OK) {
            return 0;
        }
    }

    return 1;
}

ULP_PDU_t* supl_read_pdu(TCPClient* client, int milliseconds) {
    ULP_PDU_t* pdu    = ALLOC_ZERO(ULP_PDU_t);
    int        result = supl_read(client, pdu, milliseconds);
    if (!result) {
        ASN_STRUCT_FREE(asn_DEF_ULP_PDU, pdu);
        return NULL;
    }
    return pdu;
}

// SUPL START message
int supl_start(TCPClient* client, CellID cell, SUPLSession* session) {
    ULP_PDU_t* ulp = supl_create_message(session, UlpMessage_PR_msSUPLSTART);
    ulp->message.choice.msSUPLSTART.locationId.status = Status_current;
    ulp->message.choice.msSUPLSTART.sETCapabilities.posTechnology
        .agpsSETassisted = true;
    ulp->message.choice.msSUPLSTART.sETCapabilities.posTechnology.agpsSETBased =
        true;
    ulp->message.choice.msSUPLSTART.sETCapabilities.prefMethod =
        PrefMethod_agpsSETBasedPreferred;

    {
        // LPP Version
        PosProtocolVersion3GPP_t* lpp_pos_protocol =
            ALLOC_ZERO(PosProtocolVersion3GPP_t);
        lpp_pos_protocol->majorVersionField     = 15;
        lpp_pos_protocol->technicalVersionField = 4;
        lpp_pos_protocol->editorialVersionField = 0;

        struct Ver2_PosProtocol_extension* pos_protocol_ext =
            ALLOC_ZERO(struct Ver2_PosProtocol_extension);
        pos_protocol_ext->lpp                   = true;
        pos_protocol_ext->posProtocolVersionLPP = lpp_pos_protocol;

        ulp->message.choice.msSUPLSTART.sETCapabilities.posProtocol
            .ver2_PosProtocol_extension = pos_protocol_ext;
    }

    {
        /* Parse Cell info structure, we are using SUPL 2, inform about it */
        CellInfo_t* cell_info =
            &ulp->message.choice.msSUPLSTART.locationId.cellInfo;
        cell_info->present = CellInfo_PR_ver2_CellInfo_extension;

        Ver2_CellInfo_extension_t* cell_v2 =
            &cell_info->choice.ver2_CellInfo_extension;
        cell_v2->present = Ver2_CellInfo_extension_PR_lteCell;

        /* We are using LTE here, set the cell choice */
        LteCellInformation_t* lte_cell = &cell_v2->choice.lteCell;

        /* Set LTE parameters */
        lte_cell->cellGlobalIdEUTRA.plmn_Identity.mcc =
            supl_create_mcc(cell.mcc);
        supl_fill_mnc(&lte_cell->cellGlobalIdEUTRA.plmn_Identity.mnc, cell.mnc);
        supl_fill_tracking_area_code(&lte_cell->trackingAreaCode, cell.tac);
        supl_fill_cell_identity(&lte_cell->cellGlobalIdEUTRA.cellIdentity,
                                cell.cell);

        /* Set the remaining LTE parameters */
        lte_cell->physCellId          = 0;
        lte_cell->rsrpResult          = OPTIONAL_MISSING;
        lte_cell->rsrqResult          = OPTIONAL_MISSING;
        lte_cell->measResultListEUTRA = OPTIONAL_MISSING;
    }

    { ulp->message.choice.msSUPLSTART.locationId.status = Status_unknown; }

    int result = supl_send_pdu(client, ulp);
    supl_free_message(ulp);
    return result;
}

// Helper function for wait/receiving a SUPL response
int supl_response(TCPClient* client, SUPLSession* session) {
    ULP_PDU_t* ulp = supl_read_pdu(client, -1);
    if (!ulp)
        return 0;

    int result = 0;
    if (ulp->message.present == UlpMessage_PR_msSUPLRESPONSE) {
        supl_session_harvest(session, ulp);
        result = 1;
    }

    supl_free_message(ulp);
    return result;
}

// Helper function to send SUPL POSINIT with LPP messages.
int supl_send_posinit(TCPClient* client, CellID cell, SUPLSession* session,
                      OCTET_STRING** lpp_messages, int lpp_message_count) {
    ULP_PDU_t* ulp = supl_create_message(session, UlpMessage_PR_msSUPLPOSINIT);
    ulp->message.choice.msSUPLPOSINIT.locationId.status = Status_current;
    ulp->message.choice.msSUPLPOSINIT.sETCapabilities.posTechnology
        .agpsSETassisted = true;
    ulp->message.choice.msSUPLPOSINIT.sETCapabilities.posTechnology
        .agpsSETBased = true;
    ulp->message.choice.msSUPLPOSINIT.sETCapabilities.prefMethod =
        PrefMethod_agpsSETBasedPreferred;

    {
        // LPP
        struct Ver2_PosProtocol_extension* posprotocol_ext =
            ALLOC_ZERO(struct Ver2_PosProtocol_extension);
        posprotocol_ext->lpp = true;
        ulp->message.choice.msSUPLPOSINIT.sETCapabilities.posProtocol
            .ver2_PosProtocol_extension = posprotocol_ext;

        // LPP Version
        struct PosProtocolVersion3GPP* posprotocol_lpp =
            ALLOC_ZERO(struct PosProtocolVersion3GPP);
        posprotocol_lpp->majorVersionField     = 16;
        posprotocol_lpp->technicalVersionField = 4;
        posprotocol_lpp->editorialVersionField = 0;
        posprotocol_ext->posProtocolVersionLPP = posprotocol_lpp;
    }

    {
        /* Parse Cell info structure, we are using SUPL 2, inform about it */
        CellInfo_t* cell_info =
            &ulp->message.choice.msSUPLPOSINIT.locationId.cellInfo;
        cell_info->present = CellInfo_PR_ver2_CellInfo_extension;

        Ver2_CellInfo_extension_t* cell_v2 =
            &cell_info->choice.ver2_CellInfo_extension;
        cell_v2->present = Ver2_CellInfo_extension_PR_lteCell;

        /* We are using LTE here, set the cell choice */
        LteCellInformation_t* lte_cell = &cell_v2->choice.lteCell;

        /* Set LTE parameters */
        lte_cell->cellGlobalIdEUTRA.plmn_Identity.mcc =
            supl_create_mcc(cell.mcc);
        supl_fill_mnc(&lte_cell->cellGlobalIdEUTRA.plmn_Identity.mnc, cell.mnc);
        supl_fill_tracking_area_code(&lte_cell->trackingAreaCode, cell.tac);
        supl_fill_cell_identity(&lte_cell->cellGlobalIdEUTRA.cellIdentity,
                                cell.cell);

        /* Set the remaining LTE parameters */
        lte_cell->physCellId          = 0;
        lte_cell->rsrpResult          = OPTIONAL_MISSING;
        lte_cell->rsrqResult          = OPTIONAL_MISSING;
        lte_cell->measResultListEUTRA = OPTIONAL_MISSING;
    }

    // LPP messages/payloads
    // Ericsson server is not expecting any LPP stuff in the SUPL POSINIT
    // but there is possible to send stuff here.
    if (lpp_message_count > 0) {
        auto payload = ALLOC_ZERO(
            Ver2_PosPayLoad_extension::Ver2_PosPayLoad_extension__lPPPayload);
        asn_sequence_empty(&payload->list);
        for (int i = 0; i < lpp_message_count; i++) {
            asn_sequence_add(&payload->list, lpp_messages[i]);
        }

        SUPLPOS_t* supl_pos          = ALLOC_ZERO(SUPLPOS_t);
        supl_pos->posPayLoad.present = PosPayLoad_PR_ver2_PosPayLoad_extension;
        supl_pos->posPayLoad.choice.ver2_PosPayLoad_extension.lPPPayload =
            payload;
        ulp->message.choice.msSUPLPOSINIT.sUPLPOS = supl_pos;
    }

    int result = supl_send_pdu(client, ulp);
    supl_free_message(ulp);
    return result;
}

// Helper function for receiving SUPL POS responses.
int supl_receive_pos(TCPClient* client, LPP_Message** messages, int* count,
                     int messages_size, int milliseconds) {
    assert(messages);
    assert(count);

    ULP_PDU_t* ulp = supl_read_pdu(client, milliseconds);
    if (!ulp)
        return 0;

    *count     = 0;
    int result = 0;
    if (ulp->message.present == UlpMessage_PR_msSUPLPOS &&
        ulp->message.choice.msSUPLPOS.posPayLoad.present ==
            PosPayLoad_PR_ver2_PosPayLoad_extension) {
        int lpp_message_count =
            ulp->message.choice.msSUPLPOS.posPayLoad.choice
                .ver2_PosPayLoad_extension.lPPPayload->list.count;
        for (int i = 0; i < lpp_message_count; i++) {
            if (i >= messages_size) {
                break;
            }

            OCTET_STRING* encoded_lpp =
                ulp->message.choice.msSUPLPOS.posPayLoad.choice
                    .ver2_PosPayLoad_extension.lPPPayload->list.array[i];
            LPP_Message* lpp = lpp_decode(encoded_lpp);
            assert(messages && count);
            messages[(*count)++] = lpp;
        }

        result = 1;
    }

    supl_free_message(ulp);
    return result;
}

// Helper function for sending a SUPL POS message with LPP payloads.
int supl_send_pos(TCPClient* client, SUPLSession* session,
                  OCTET_STRING* lpp_message) {
    ULP_PDU_t* ulp = supl_create_message(session, UlpMessage_PR_msSUPLPOS);

    {
        auto payload = ALLOC_ZERO(
            Ver2_PosPayLoad_extension::Ver2_PosPayLoad_extension__lPPPayload);
        asn_sequence_empty(&payload->list);
        asn_sequence_add(&payload->list, lpp_message);
        SUPLPOS_t* supl_pos          = &ulp->message.choice.msSUPLPOS;
        supl_pos->posPayLoad.present = PosPayLoad_PR_ver2_PosPayLoad_extension;
        supl_pos->posPayLoad.choice.ver2_PosPayLoad_extension.lPPPayload =
            payload;
    }

    int result = supl_send_pdu(client, ulp);
    supl_free_message(ulp);
    return result;
}
