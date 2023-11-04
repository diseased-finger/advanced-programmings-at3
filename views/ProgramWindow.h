//
// Created by jedsaxon on 2/11/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT3_PROGRAMWINDOW_H
#define ADVANCED_PROGRAMMINGS_AT3_PROGRAMWINDOW_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include "../routing/RouteManager.h"

class ProgramWindow : public Gtk::Window {
public:
    explicit ProgramWindow();
protected:
    RouteManager* router;
    void Load(std::string routeName);
};

#endif //ADVANCED_PROGRAMMINGS_AT3_PROGRAMWINDOW_H
