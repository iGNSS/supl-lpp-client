#include "tcp.h"

#include <string.h>

#if USE_OPENSSL
static void tls_init(void) {
    SSL_load_error_strings();
    SSLeay_add_ssl_algorithms();
}
#endif

void network_initialize() {
#if USE_OPENSSL
    tls_init();
#endif
}

void network_cleanup() {}

//
// TCP Client
//

static int _tcp_client_socket(TCPClient* client) {
    int              fd = -1;
    struct addrinfo *ailist, *aip;
    struct addrinfo  hint;
    int              err;

    memset(&hint, 0, sizeof(struct addrinfo));
    hint.ai_socktype = SOCK_STREAM;

    char portstr[6];
    sprintf(portstr, "%i", client->port);

    err = getaddrinfo(client->server, portstr, &hint, &ailist);
    if (err != 0) {
        return 0;
    }

    for (aip = ailist; aip; aip = aip->ai_next) {
        char host[256];
        getnameinfo(aip->ai_addr, aip->ai_addrlen, host, sizeof(host), NULL, 0,
                    NI_NUMERICHOST);
        if ((fd = socket(aip->ai_family, SOCK_STREAM, 0)) < 0) {
            err = errno;
        }

        if (connect(fd, aip->ai_addr, aip->ai_addrlen) != 0) {
            freeaddrinfo(ailist);
            return 0;
        }

        break;
    }

    client->socket = fd;
    freeaddrinfo(ailist);
    return 1;
}

int tcp_client_create(TCPClient* client, const char* server, int port,
                      int use_ssl) {
    memset(client, 0, sizeof(*client));
    client->server  = server;
    client->port    = port;
    client->use_ssl = use_ssl;
    client->socket  = -1;
    return 1;
}

int tcp_client_connect(TCPClient* client) {
    if (client->socket >= 0)
        return 0;

    if (client->use_ssl) {
#if USE_OPENSSL
        client->ssl_method =
#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
            TLSv1_2_client_method();
#else
            TLS_client_method();
#endif
        client->ssl_ctx = SSL_CTX_new(client->ssl_method);
        if (!client->ssl_ctx)
            return 0;

        client->ssl = SSL_new(client->ssl_ctx);
        if (!client->ssl)
            return 0;
#else
        return 0;
#endif
    } else {
#if USE_OPENSSL
        client->ssl_method = NULL;
        client->ssl_ctx    = NULL;
        client->ssl        = NULL;
#endif
    }

    if (!_tcp_client_socket(client)) {
        return 0;
    }

#if USE_OPENSSL
    if (client->use_ssl) {
        SSL_set_fd(client->ssl, client->socket);
        if (SSL_connect(client->ssl) == -1) {
            return 0;
        }
    }
#endif

    return 1;
}

void tcp_client_close(TCPClient* client) {
#if USE_OPENSSL
    if (client->use_ssl) {
        SSL_shutdown(client->ssl);
        SSL_free(client->ssl);
        SSL_CTX_free(client->ssl_ctx);
    }

    client->ssl_method = NULL;
    client->ssl_ctx    = NULL;
    client->ssl        = NULL;
#endif

    close(client->socket);
    client->socket = -1;
}

int tcp_client_receive(TCPClient* client, void* buffer, int size,
                       int milliseconds) {
    if (milliseconds >= 0) {
        struct timeval timeout;
        timeout.tv_sec  = (milliseconds / 1'000);
        timeout.tv_usec = (milliseconds % 1'000) * 1'000;

        auto timeout_ptr = &timeout;
        if (milliseconds == 0) {
            timeout_ptr = NULL;
        }

        fd_set sock;
        FD_ZERO(&sock);
        FD_SET(client->socket, &sock);

        int status = select(client->socket + 1, &sock, NULL, NULL, timeout_ptr);
        if (status < 0) {
            tcp_client_close(client);
            return -1;
        }

        if (status == 0)
            return 0;
    }

#if USE_OPENSSL
    if (client->use_ssl)
        return SSL_read(client->ssl, buffer, size);
    else
        return read(client->socket, buffer, size);
#else
    return read(client->socket, buffer, size);
#endif
}

int tcp_client_send(TCPClient* client, void* buffer, int size) {
#if USE_OPENSSL
    if (client->use_ssl)
        return SSL_write(client->ssl, buffer, size);
    else
        return write(client->socket, buffer, size);
#else
    return write(client->socket, buffer, size);
#endif
}

bool tcp_client_is_connected(TCPClient* client) {
    return client->socket > 0;
}
