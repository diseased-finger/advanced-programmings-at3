//
// Created by jedsaxon on 6/11/23.
//

#include "ProgramWindow.h"
#include "views/HomeView.h"
#include "views/ConnectToServerView.h"
#include "views/ServerInterfaceView.h"
#include "views/ClientInterfaceView.h"

ProgramWindow::ProgramWindow() {
    RouteToHomeView();
}

void ProgramWindow::RouteToHomeView() {
    if (get_child())
        delete get_child();

    if (homeView == nullptr)
        homeView = new HomeView(this);

    set_child(*homeView);
    homeView->show();
}

void ProgramWindow::RouteToConnectToServerView() {
    if (get_child())
        delete get_child();

    if (connectToServerView == nullptr)
        connectToServerView = new ConnectToServerView(this);

    set_child(*connectToServerView);
}

void ProgramWindow::RouteToServerInterfaceView() {
    if (get_child())
        delete get_child();

    if (serverInterfaceView == nullptr)
        serverInterfaceView = new ServerInterfaceView(this);

    set_child(*serverInterfaceView);
}

void ProgramWindow::RouteToClientInterfaceView() {
    if (get_child())
        delete get_child();

    if (clientInterfaceView == nullptr)
        clientInterfaceView = new ClientInterfaceView(this);

    set_child(*clientInterfaceView);
}
