//
// Created by jedsaxon on 2/11/23.
//

#include "Router.h"
#include "../exceptions/NotFoundException.h"

Router::Router(Route **_routes, int _routeCount, int _landingIndex) :
        routes(_routes),
        routeCount(_routeCount) ,
        landingIndex(_landingIndex) {}

Route* Router::Resolve(const std::string &route) {
    for (int i = 0; i < routeCount; ++i) {
        if (strcmp(routes[i]->route.c_str(), route.c_str()) == 0) {
            return routes[i];
        }
    }
    throw NotFoundException();
}
