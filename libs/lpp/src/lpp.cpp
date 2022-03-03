#include "lpp.h"
#include "internal_lpp.h"
#include "supl.h"
#include "tcp.h"

LPP_Client::LPP_Client() {
    connected           = false;
    main_request        = AD_REQUEST_INVALID;
    provide_li.type     = -1;
    transaction_counter = 1;
    client_id           = 0xC0DEC0DE;
    tcp                 = new TCPClient();
    session             = new SUPLSession();
}

LPP_Client::~LPP_Client() {
    if (connected) {
        tcp_client_close(tcp);
    }

    delete session;
    delete tcp;
}

bool LPP_Client::connect(const char* address, int port, bool use_ssl, CellID supl_cell) {
    // Initialize and connect to the location server
    tcp_client_create(tcp, address, port, use_ssl);
    if (!tcp_client_connect(tcp)) {
        return false;
    }

    // Create SUPL session
    supl_session_create(session, client_id);

    // Send SUPL-START request
    if (!supl_start(tcp, supl_cell, session)) {
        tcp_client_close(tcp);
        return false;
    }

    // Wait for SUPL-RESPONSE with slp session
    if (!supl_response(tcp, session)) {
        tcp_client_close(tcp);
        return false;
    }

    // Send SUPL-POSINIT
    if (!supl_send_posinit(tcp, supl_cell, session, NULL, 0)) {
        tcp_client_close(tcp);
        return false;
    }

    connected = true;

    // Old servers requires a few messages in the begining of the LPP session.
    struct timespec timeout;
    timeout.tv_sec  = 0;
    timeout.tv_nsec = 1'000'000 * 1009;  // 1 sec
    nanosleep(&timeout, NULL);

    process();

    return true;
}

LPP_Transaction LPP_Client::new_transaction() {
    LPP_Transaction transaction;
    transaction.id        = transaction_counter;
    transaction.end       = 0;
    transaction.initiator = 0;

    transaction_counter = (transaction_counter + 1) % 256;
    return transaction;
}

bool LPP_Client::process_message(LPP_Message* message, LPP_Transaction* transaction) {
    auto periodic_id = lpp_get_periodic_id(message);
    if (lpp_is_provide_assistance_data(message)) {
        // printf("%li == %i %li == %li\n", periodic_id, main_request, transaction->id,
        //       main_request_transaction.id);
        // xer_fprint(stdout, &asn_DEF_LPP_Message, message);
        if ((periodic_id == main_request || transaction->id == main_request_transaction.id) &&
            main_request >= 0) {
            if (main_request_callback) {
                main_request_callback(this, transaction, message, main_request_userdata);
            }
        }
        return true;
    } else if (lpp_is_request_capabilities(message)) {
        transaction->end = true;

        auto octet = lpp_provide_capabilities(transaction);
        if (!supl_send_pos(tcp, session, octet)) {
            tcp_client_close(tcp);
            connected = false;
            return false;
        }
    } else if (lpp_is_request_location_information(message)) {
        return handle_request_location_information(message, transaction);
    }

    return false;
}

bool LPP_Client::process() {
    if (!tcp_client_is_connected(tcp)) {
        return false;
    }

    LPP_Message* messages[8];
    if (provide_li.type >= 0) {
        using namespace std::chrono;
        auto current  = system_clock::now();
        auto duration = current - provide_li.last;
        if (duration > 1s) {
            handle_provide_location_information(&provide_li);
            provide_li.last = current - (duration - 1s);
        }
    }

    int timeout       = 0;
    int message_count = 0;
    if (!supl_receive_pos(tcp, messages, &message_count, 8, timeout)) {
        if (!tcp_client_is_connected(tcp)) {
            return false;
        }

        return true;
    }

    for (int j = 0; j < message_count; j++) {
        auto message = messages[j];

        LPP_Transaction transaction;
        if (!lpp_harvest_transaction(&transaction, message)) {
            lpp_destroy(message);
            continue;
        }

        process_message(message, &transaction);
        lpp_destroy(message);
    }

    return true;
}

bool LPP_Client::wait_for_assistance_data_response(LPP_Transaction* transaction) {
    bool ok   = false;
    auto last = time(NULL);
    while (time(NULL) - last < 4 && !ok) {
        int          message_count = 0;
        LPP_Message* messages[8];
        if (!supl_receive_pos(tcp, messages, &message_count, 8, 4000)) {
            tcp_client_close(tcp);
            connected = false;
            return false;
        }

        for (int j = 0; j < message_count; j++) {
            auto message = messages[j];

            LPP_Transaction message_transaction;
            if (!lpp_harvest_transaction(&message_transaction, message)) {
                lpp_destroy(message);
                continue;
            }

            process_message(message, &message_transaction);

            // NOTE: message_transaction.initiator == transaction->initiator
            // cannot be use as old server didn't correctly handle initiator
            if (message_transaction.id == transaction->id) {
                if (message && message->lpp_MessageBody &&
                    message->lpp_MessageBody->present == LPP_MessageBody_PR_c1 &&
                    message->lpp_MessageBody->choice.c1.present ==
                        LPP_MessageBody__c1_PR_provideAssistanceData) {
                    ok = true;
                } else {
                    last -= 100000;
                }
            }

            lpp_destroy(message);
        }
    }

    return ok;
}

LPP_Client::AD_Request LPP_Client::request_assistance_data(CellID cell, void* userdata,
                                                           AD_Callback callback) {
    if (main_request != AD_REQUEST_INVALID) return AD_REQUEST_INVALID;

    auto periodic_id = 1;  // TODO(ewasjon): support multiple requests
    auto transaction = new_transaction();
    auto octet       = lpp_request_assistance_data(&transaction, cell, periodic_id, 1);
    if (!supl_send_pos(tcp, session, octet)) {
        tcp_client_close(tcp);
        connected = false;
        return AD_REQUEST_INVALID;
    }

    main_request             = (AD_Request)periodic_id;
    main_request_callback    = callback;
    main_request_userdata    = userdata;
    main_request_transaction = transaction;
    if (!wait_for_assistance_data_response(&transaction)) {
        main_request = AD_REQUEST_INVALID;
        return AD_REQUEST_INVALID;
    }

    return (AD_Request)periodic_id;
}

LPP_Client::AD_Request LPP_Client::request_assistance_data_ssr(CellID cell, void* userdata,
                                                               AD_Callback callback) {
    if (main_request != AD_REQUEST_INVALID) return AD_REQUEST_INVALID;

    auto periodic_id = 1;  // TODO(ewasjon): support multiple requests
    auto transaction = new_transaction();
    auto octet       = lpp_request_assistance_data_ssr(&transaction, cell, periodic_id, 1);
    if (!supl_send_pos(tcp, session, octet)) {
        tcp_client_close(tcp);
        connected = false;
        return AD_REQUEST_INVALID;
    }

    main_request             = (AD_Request)periodic_id;
    main_request_callback    = callback;
    main_request_userdata    = userdata;
    main_request_transaction = transaction;
    if (!wait_for_assistance_data_response(&transaction)) {
        main_request = AD_REQUEST_INVALID;
        return AD_REQUEST_INVALID;
    }

    return (AD_Request)periodic_id;
}

bool LPP_Client::update_assistance_data(AD_Request id, CellID cell) {
    if (id != main_request) return false;
    if (id == AD_REQUEST_INVALID) return false;

    auto transaction = new_transaction();
    auto octet       = lpp_request_assistance_data(&transaction, cell, (long)id, 1);
    if (!supl_send_pos(tcp, session, octet)) {
        tcp_client_close(tcp);
        connected = false;
        return false;
    }

    main_request_transaction = transaction;
    if (!wait_for_assistance_data_response(&transaction)) {
        return false;
    }

    return true;
}

bool LPP_Client::cancel_assistance_data(AD_Request id) {
    if (id != main_request) return false;
    return false;
}

void LPP_Client::provide_location_information_callback(void*                    userdata,
                                                       LPP_Client::PLI_Callback callback) {
    pli_callback = callback;
    pli_userdata = userdata;
}

void LPP_Client::provide_ecid_callback(void* userdata, LPP_Client::PECID_Callback callback) {
    pecid_callback = callback;
    pecid_userdata = userdata;
}

bool LPP_Client::handle_request_location_information(LPP_Message*     message,
                                                     LPP_Transaction* transaction) {
    switch (lpp_get_request_location_information_type(message)) {
    case LocationInformationType_locationEstimateRequired:
        provide_li.type        = LocationInformationType_locationEstimateRequired;
        provide_li.last        = std::chrono::system_clock::now();
        provide_li.transaction = *transaction;
        return true;
    case LocationInformationType_locationMeasurementsRequired:
        provide_li.type        = LocationInformationType_locationMeasurementsRequired;
        provide_li.last        = std::chrono::system_clock::now();
        provide_li.transaction = *transaction;
        return true;
    case LocationInformationType_locationMeasurementsPreferred:
        provide_li.type        = LocationInformationType_locationMeasurementsPreferred;
        provide_li.last        = std::chrono::system_clock::now();
        provide_li.transaction = *transaction;
        return true;
    case LocationInformationType_locationEstimatePreferred:
        provide_li.type        = LocationInformationType_locationEstimatePreferred;
        provide_li.last        = std::chrono::system_clock::now();
        provide_li.transaction = *transaction;
        return true;
    }

    return false;
}

bool LPP_Client::handle_provide_location_information(LPP_Client::ProvideLI* pli) {
    OCTET_STRING* octet = NULL;
    if (pli->type == LocationInformationType_locationEstimateRequired) {
        LocationInformation li{};
        bool                has_information = false;
        if (pli_callback && pli_callback(&li, pli_userdata)) {
            has_information = true;
        }

        octet = lpp_PLI_location_estimate(&pli->transaction, &li, has_information);
    } else if (pli->type == LocationInformationType_locationMeasurementsRequired) {
        ECIDInformation ecid{};
        bool            has_information = false;
        if (!pecid_callback || !pecid_callback(&ecid, pecid_userdata)) {
            has_information = true;
        }

        octet = lpp_PLI_location_measurements(&pli->transaction, &ecid, has_information);
    } else {
        return false;
    }

    assert(octet);
    if (!supl_send_pos(tcp, session, octet)) {
        return false;
    }

    return false;
}