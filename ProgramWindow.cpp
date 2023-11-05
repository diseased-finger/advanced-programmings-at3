//
// Created by jedsaxon on 6/11/23.
//

#include "ProgramWindow.h"
#include "views/HomeView.h"
#include "views/ConnectToServerView.h"

ProgramWindow::ProgramWindow() {
    homeView = new HomeView(this);
    connectToServerBox = new ConnectToServerView(this);
    RouteToHomeView();
}

void ProgramWindow::RouteToHomeView() {
    set_child(*homeView);
}

void ProgramWindow::RouteToConnectToServerView() {
    set_child(*connectToServerBox);
}
