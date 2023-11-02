//
// Created by jedsaxon on 2/11/23.
//

#include "ProgramWindow.h"
#include "MainView.h"
#include "../exceptions/NotFoundException.h"
#include <gtkmm.h>
#include <iostream>

ProgramWindow::ProgramWindow() {
    // Initialise RouteManager
    auto **routes = new Route *[1];
    routes[0] = new Route("", new MainView());
    router = new RouteManager(routes, 1, 0);

//    set_child(box_w);

    // Set Properties
    set_title("Advanced Programming - AT3");
    set_default_size(1000, 1000);

    // Load Landing Page
    Load("");
}

void ProgramWindow::Load(std::string routeName) {
    // Get Route
    Route* r = nullptr;
    try {
        r = router->Resolve(routeName);
    } catch (std::exception e) {
        printf("Route %s not found. Unable to load", routeName.c_str());
    }

    // Set Program's Child to Route's Widget
    set_child(*r->widget);
}
