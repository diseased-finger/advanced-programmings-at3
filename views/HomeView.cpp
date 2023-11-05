//
// Created by jedsaxon on 6/11/23.
//

#include "HomeView.h"

HomeView::HomeView(ProgramWindow* window) {
    this->window = window;
    set_orientation(Gtk::Orientation::VERTICAL);

    w_label = Gtk::Label("Test");
    append(w_label);

    w_connectToServerButton = Gtk::Button("Connect To Server");
    w_connectToServerButton.signal_clicked().connect(sigc::mem_fun(*this, &HomeView::S_ConnectToServerButtonClick));
    append(w_connectToServerButton);

    w_createServerButton = Gtk::Button("Create Server");
    w_createServerButton.signal_clicked().connect(sigc::mem_fun(*this, &HomeView::S_CreateServerButtonClick));
    append(w_createServerButton);
}

void HomeView::S_ConnectToServerButtonClick() {
    window->RouteToConnectToServerView();
}

void HomeView::S_CreateServerButtonClick() {
    window->RouteToServerInterfaceView();
}
