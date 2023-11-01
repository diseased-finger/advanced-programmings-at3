//
// Created by jedsaxon on 2/11/23.
//

#include <string>
#include <utility>
#include <utility>
#include <gtkmm.h>

#ifndef ADVANCED_PROGRAMMINGS_AT3_ROUTE_H
#define ADVANCED_PROGRAMMINGS_AT3_ROUTE_H


struct Route {
public:
    Route(std::string _route, Gtk::Widget* _widget) :
        route(std::move(std::move(_route))),
        widget(_widget) { };

    std::string route;
    Gtk::Widget* widget;
};

#endif //ADVANCED_PROGRAMMINGS_AT3_ROUTE_H