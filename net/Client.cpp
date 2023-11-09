//
// Created by jedsaxon on 9/11/23.
//

#include "Client.h"
#include "exceptions/GeneralNetError.h"

Client::Client(std::string _hostname, int _port) :
    hostname(_hostname),
    port(_port) {

}

void Client::SendMessage(std::string msg) {
    // -- Create client file descriptor --
    int clientFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (clientFileDescriptor < 0)
    {
        printf("Socket creation error\n");
        return;
    }

    // -- Create an address to connect to --
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = port;

    if (inet_pton(AF_INET, hostname.c_str(), &serverAddress.sin_addr) <= 0)
        throw GeneralNetError("Invalid address / Address not supported");

    // -- Actually Connect --
    int connectResult = connect(
        clientFileDescriptor,
        (struct sockaddr*)&serverAddress,
        sizeof(serverAddress)
    );

    if (connectResult < 0)
        throw GeneralNetError("Unable to connect to server");

    // -- Send Data --
    send(clientFileDescriptor, msg.c_str(), strlen(msg.c_str()), 0);

    char buffer[1024] = { 0 };
    int valread = read(clientFileDescriptor, buffer, 1024 - 1);
    close(clientFileDescriptor);

    return;
}
