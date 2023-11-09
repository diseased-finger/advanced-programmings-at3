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
    struct sockaddr_in address;
public:
    Server(int _port);
    ~Server();
    void Serve(bool log = false);

    /// Waits for a response in another thread for performance reasons
    void Listen(int serverFileDescriptor, bool log = false);

    void Stop();

    int CreateSocket(bool log);
};


#endif //ADVANCED_PROGRAMMINGS_AT3_SERVER_H
