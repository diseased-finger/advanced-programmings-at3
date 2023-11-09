//
// Created by jedsaxon on 7/11/23.
//

#include <csignal>
#include "Server.h"
#include "exceptions/ListenError.h"

Server::Server(int _port) :
    port(_port) {
    address.sin_family = AF_INET; // Define protocol as INET (ipv4. Eg: 127.0.0.1)
    address.sin_addr.s_addr = INADDR_ANY; // Say that any address can be used to communicate with socket
    address.sin_port = port;
}

void Server::Serve(bool log) {
    int opt = 1;

    // -- Create the socket --
    int serverFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFileDescriptor < 0) {
        throw SocketError("Socket was unable to be created");;
    }
    else if (log)
        printf("Server: Socket Created\n");

    // -- Bind socket to address --
    int bindResult = bind(
            serverFileDescriptor,
            (struct sockaddr*)&address,
            sizeof(address)
    );

    if (bindResult < 0) // If it is equal to 1, success. Otherwise, throw error
        throw SocketError("Unable to bind socket to address");
    else if (log)
        printf("Server: Bound socket to address. Ready to listen\n");

    char buffer[1024] = { 0 };

    int listenResult = listen(serverFileDescriptor, 3);
    if (listenResult < 0)
        throw ListenError("Was unable to listen as server");
    else if (log)
        printf("Server: Listening on port: %i\n", port);

    int acceptResult;
    socklen_t addressLength = sizeof(address);
    acceptResult = accept(
            serverFileDescriptor,
            (struct sockaddr*)&address,
            &addressLength);
    if (acceptResult < 0) {
        switch (errno) {
            case EAGAIN:
                printf("%i: EAGAIN or EWOULDBLOCK\n", errno);
                break;
            case EBADF:
                printf("%i: EBADF\n", errno);
                break;
            case ECONNABORTED:
                printf("%i: ECONNABORTED\n", errno);
                break;
            case EFAULT:
                printf("%i: EFAULT\n", errno);
                break;
            case EINTR:
                printf("%i: EINTR\n", errno);
                break;
            case EINVAL:
                printf("%i: EINVAL\n", errno);
                break;
            case EMFILE:
                printf("%i: EMFILE\n", errno);
                break;
            case ENFILE:
                printf("%i: ENFILE\n", errno);
                break;
            case ENOBUFS:
                printf("%i: ENOBUFS\n", errno);
                break;
            case ENOMEM:
                printf("%i: ENOMEM\n", errno);
                break;
            case ENOTSOCK:
                printf("%i: ENOTSOCK\n", errno);
                break;
            case EPERM:
                printf("%i: EPERM\n", errno);
                break;
            case EPROTO:
                printf("%i: EPROTO\n", errno);
                break;
            case ENOSR:
                printf("%i: ENOSR\n", errno);
                break;
            case ESOCKTNOSUPPORT:
                printf("%i: ESOCKTNOSUPPORT\n", errno);
                break;
            case EPROTONOSUPPORT:
                printf("%i: EPROTONOSUPPORT\n", errno);
                break;
            case ETIMEDOUT:
                printf("%i: ETIMEDOUT\n", errno);
                break;
            case ERESTART:
                printf("%i: ERESTART\n", errno);
                break;
            default:
                printf("%i: No constant equals this\n", errno);
                break;
        }
        exit(-1);
    }

    printf("Server: Response Found. Parsing it\n");

    ssize_t valueRead = read(acceptResult, buffer, 1024-1);
    std::cout << "Buffer: " << buffer << std::endl;

    close(acceptResult);
    close(serverFileDescriptor);
}

Server::~Server() {

}

void Server::Stop() {
    printf("Server: Stopping Server\n");
}
