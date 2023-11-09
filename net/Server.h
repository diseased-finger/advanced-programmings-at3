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
#include <csignal>
#include <thread>
#include "exceptions/ListenError.h"
#include "../net/Server.h"
#include "../net/exceptions/ListenError.h"

class Server {
public:
    std::string Serve(bool log = false);

    void Stop();
};


#endif //ADVANCED_PROGRAMMINGS_AT3_SERVER_H
