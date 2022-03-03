#pragma once

#include <asnlib.h>
#include <cell_id.h>
#include "tcp.h"

struct SUPLSession {
    int           id;
    int           slp_size;
    char*         slp_buffer;
    unsigned char ip[4];
};

void supl_session_create(SUPLSession* session, uint32_t ip);

int supl_session_harvest(SUPLSession* session, ULP_PDU_t* ulp);

// Helper function for creating a SUPL message.
ULP_PDU_t* supl_create_message(SUPLSession* session, UlpMessage_PR present);

void supl_free_message(ULP_PDU_t* ulp);

// Helper function to send a SUPL message.
int supl_send_pdu(TCPClient* client, ULP_PDU_t* ulp);

// Helper to read SUPL messages
int supl_read(TCPClient* client, ULP_PDU_t* pdu);

ULP_PDU_t* supl_read_pdu(TCPClient* client, int milliseconds);

// SUPL START message
int supl_start(TCPClient* client, CellID cell, SUPLSession* session);

// Helper function for wait/receiving a SUPL response
int supl_response(TCPClient* client, SUPLSession* session);

// Helper function to send SUPL POSINIT with LPP messages.
int supl_send_posinit(TCPClient* client, CellID cell, SUPLSession* session,
                      OCTET_STRING** lpp_messages, int lpp_message_count);

// Helper function for receiving SUPL POS responses.
int supl_receive_pos(TCPClient* client, LPP_Message** messages, int* count, int messages_size,
                     int milliseconds);

// Helper function for sending a SUPL POS message with LPP payloads.
int supl_send_pos(TCPClient* client, SUPLSession* session, OCTET_STRING* lpp_message);
