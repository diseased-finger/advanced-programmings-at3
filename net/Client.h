//
// Created by jedsaxon on 9/11/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT3_CLIENT_H
#define ADVANCED_PROGRAMMINGS_AT3_CLIENT_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <csignal>
#include <cstring>
#include <iostream>
#include <arpa/inet.h>
#include <cstdlib>
#include <cstring>
#include <sys/socket.h>
#include <unistd.h>

class Client {
private:
    std::string hostname;
    int port;
public:
    Client(std::string _hostname, int _port);
    void SendMessage(std::string msg);
};


#endif //ADVANCED_PROGRAMMINGS_AT3_CLIENT_H
