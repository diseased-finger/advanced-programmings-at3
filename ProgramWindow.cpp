//
// Created by jedsaxon on 6/11/23.
//

#include "ProgramWindow.h"
#include "views/HomeView.h"

ProgramWindow::ProgramWindow() {
    RouteToHomeView();
}

void ProgramWindow::RouteToHomeView() {
    Gtk::Box box = HomeView();
    set_child(box);
}
