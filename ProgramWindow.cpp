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
    homeView = new HomeView(this);
    RouteTo(homeView);
}

void ProgramWindow::RouteToConnectToServerView() {
    connectToServerView = new ConnectToServerView(this);
    RouteTo(connectToServerView);
}

void ProgramWindow::RouteToServerInterfaceView() {
    serverInterfaceView = new ServerInterfaceView(this);
    RouteTo(serverInterfaceView);
}

void ProgramWindow::RouteToClientInterfaceView() {
    clientInterfaceView = new ClientInterfaceView(this);
    RouteTo(clientInterfaceView);
}

void ProgramWindow::RouteTo(Gtk::Box *b) {
    if (current != nullptr && current != b)
    {
        unset_child();
        delete current;
    }

    if (current == b) {
        printf("Same View. Not Changing\n");
    }

    set_child(*b);
    b->show();
    current = b;
}
