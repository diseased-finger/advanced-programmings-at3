//
// Created by jedsaxon on 6/11/23.
//

#include "ProgramWindow.h"
#include "views/HomeView.h"
#include "views/ConnectToServerView.h"

ProgramWindow::ProgramWindow() {
    homeView = new HomeView();
    connectToServerBox = new ConnectToServerView(this);
    RouteToConnectToServerView();
}

void ProgramWindow::RouteToHomeView() {
    set_child(*homeView);
}

void ProgramWindow::RouteToConnectToServerView() {
    set_child(*connectToServerBox);
}
