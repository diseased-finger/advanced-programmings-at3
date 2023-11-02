//
// Created by jedsaxon on 2/11/23.
//

#include "RouteManager.h"
#include "../exceptions/NotFoundException.h"
#include "../views/ProgramWindow.h"

RouteManager::RouteManager(Route **_routes, int _routeCount, int _landingIndex) :
        routes(_routes),
        routeCount(_routeCount) ,
        landingIndex(_landingIndex) {}

Route* RouteManager::Resolve(const std::string &route) {
    // Find Route
    Route* r = nullptr;
    for (int i = 0; i < routeCount; ++i) {
        if (strcmp(routes[i]->route.c_str(), route.c_str()) == 0) {
            return routes[i];
        }
    }

    throw NotFoundException();
}
