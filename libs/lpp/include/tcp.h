#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#if USE_OPENSSL
#include <openssl/crypto.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/x509.h>
#endif

struct TCPClient {
    const char* server;
    int         port;
    int         use_ssl;

    int socket;

#if USE_OPENSSL
    const SSL_METHOD* ssl_method;
    SSL_CTX*          ssl_ctx;
    SSL*              ssl;
#endif
};

int  tcp_client_create(TCPClient* client, const char* server, int port,
                       int use_ssl);
int  tcp_client_connect(TCPClient* client);
void tcp_client_close(TCPClient* client);
int  tcp_client_receive(TCPClient* client, void* buffer, int size, int milliseconds);
int  tcp_client_send(TCPClient* client, void* buffer, int size);
bool tcp_client_is_connected(TCPClient* client);
