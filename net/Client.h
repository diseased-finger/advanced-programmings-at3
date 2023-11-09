//
// Created by jedsaxon on 9/11/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT3_CLIENT_H
#define ADVANCED_PROGRAMMINGS_AT3_CLIENT_H


#include <string>

class Client {
private:
    std::string hostname;
    int port;
public:
    Client(std::string _hostname, int _port);
};


#endif //ADVANCED_PROGRAMMINGS_AT3_CLIENT_H
