//
// Created by jedsaxon on 6/11/23.
//

#include "ProgramWindow.h"
#include "views/HomeView.h"
#include "views/ClientInterfaceView.h"
#include "views/ServerInterfaceView.h"

ProgramWindow::ProgramWindow() {
    NavigateToHomeView();
}

void ProgramWindow::NavigateToHomeView() {
    homeView = new HomeView(this);
    NavigateTo(homeView);
}

void ProgramWindow::NavigateToConnectToServerView() {
    connectToServerView = new ClientInterfaceView(this);
    NavigateTo(connectToServerView);
}

void ProgramWindow::NavigateToServerInterfaceView() {
    serverInterfaceView = new ServerInterfaceView(this);
    NavigateTo(serverInterfaceView);
}

void ProgramWindow::NavigateTo(Gtk::Box *b) {
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
