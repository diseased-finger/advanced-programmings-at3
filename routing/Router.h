//
// Created by jedsaxon on 2/11/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT3_ROUTER_H
#define ADVANCED_PROGRAMMINGS_AT3_ROUTER_H


#include "Route.h"

class Router {
private:
    Route** routes;
    int routeCount;
    int landingIndex;
public:
    explicit Router(Route** _routes, int _routeCount, int _landingIndex = 0);
    Route* Resolve(const std::string& route);
};


#endif //ADVANCED_PROGRAMMINGS_AT3_ROUTER_H
