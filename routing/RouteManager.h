//
// Created by jedsaxon on 2/11/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT3_ROUTEMANAGER_H
#define ADVANCED_PROGRAMMINGS_AT3_ROUTEMANAGER_H


#include "Route.h"

class RouteManager {
private:
    Route** routes;
    int routeCount;
    int landingIndex;
public:
    explicit RouteManager(Route** _routes, int _routeCount, int _landingIndex = 0);
    Route* Resolve(const std::string& route);
};


#endif //ADVANCED_PROGRAMMINGS_AT3_ROUTEMANAGER_H
