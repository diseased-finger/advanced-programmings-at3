//
// Created by jedsaxon on 7/11/23.
//

#include "Server.h"
#include "exceptions/ListenError.h"

Server::Server(int _port) :
    port(_port) {

}

/// Creates the server to be ready to serve
void Server::Initialise(bool log) {
    int opt = 1;

    // -- Create the socket --
    serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd < 0) {
        throw SocketError("Socket was unable to be created");;
    }
    else if (log)
        printf("Server: Socket Created\n");

    // -- Bind socket to address --
    struct sockaddr_in address;
    address.sin_family = AF_INET; // Define protocol as INET (ipv4. Eg: 127.0.0.1)
    address.sin_addr.s_addr = INADDR_ANY; // Say that any address can be used to communicate with socket
    address.sin_port = port;

    int bindResult = bind(
            serverFd,
            (struct sockaddr *) &address,
            sizeof(address)
    );

    if (bindResult < 0) // If it is equal to 1, success. Otherwise, throw error
        throw SocketError("Unable to bind socket to address");
    else if (log)
        printf("Server: Bound socket to address. Ready to listen\n");
}

void Server::Serve(bool log) {
    int listenResult = listen(serverFd, 3);
    if (listenResult < 0)
        throw ListenError("Was unable to listen as server");
    else if (log)
        printf("Server: Listening on port: %i", port);
}

Server::~Server() {

}
