//
// Created by jedsaxon on 9/11/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT3_GENERALNETERROR_H
#define ADVANCED_PROGRAMMINGS_AT3_GENERALNETERROR_H

#include <string>

class GeneralNetError {
private:
    std::string msg;
public:
    explicit GeneralNetError(std::string _msg) : msg (std::move(_msg)) {};

    std::string GetMessage() { return msg; }
};
#endif //ADVANCED_PROGRAMMINGS_AT3_GENERALNETERROR_H
