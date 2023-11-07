//
// Created by jedsaxon on 7/11/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT3_SERVER_H
#define ADVANCED_PROGRAMMINGS_AT3_SERVER_H

#include "exceptions/SocketError.h"
#include <utility>
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <string>

class Server {
private:
    int port;
    int serverFd;
public:
    Server(int _port);
    ~Server();
    void Initialise(bool log = false);
    void Serve(bool log = false);

    void Stop();
};


#endif //ADVANCED_PROGRAMMINGS_AT3_SERVER_H
