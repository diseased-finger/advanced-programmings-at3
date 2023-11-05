//
// Created by jedsaxon on 6/11/23.
//

#include "ProgramWindow.h"
#include "views/HomeView.h"
#include "views/ConnectToServerView.h"
#include "views/ServerInterfaceView.h"
#include "views/ClientInterfaceView.h"

ProgramWindow::ProgramWindow() {
    homeView = new HomeView(this);
    connectToServerView = new ConnectToServerView(this);
    serverInterfaceView = new ServerInterfaceView(this);
    clientInterfaceView = new ClientInterfaceView(this);
    RouteToHomeView();
}

void ProgramWindow::RouteToHomeView() {
    set_child(*homeView);
}

void ProgramWindow::RouteToConnectToServerView() {
    set_child(*connectToServerView);
}

void ProgramWindow::RouteToServerInterfaceView() {
    set_child(*serverInterfaceView);
}

void ProgramWindow::RouteToClientInterfaceView() {
    set_child(*clientInterfaceView);
}
