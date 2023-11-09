//
// Created by jedsaxon on 7/11/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT3_SOCKETERROR_H
#define ADVANCED_PROGRAMMINGS_AT3_SOCKETERROR_H

#include <exception>
#include <string>
#include <utility>

class SocketError : std::exception {
private:
    std::string msg;
public:
    explicit SocketError(std::string _msg) : msg(std::move(_msg)) { };
    std::string GetMessage() { return msg; }
};

#endif //ADVANCED_PROGRAMMINGS_AT3_SOCKETERROR_H
