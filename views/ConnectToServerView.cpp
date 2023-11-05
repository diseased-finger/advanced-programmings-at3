//
// Created by jedsaxon on 6/11/23.
//

#include "ConnectToServerView.h"

ConnectToServerView::ConnectToServerView() {
    // Attributes
    set_orientation(Gtk::Orientation::VERTICAL);

    // Header
    w_header = Gtk::Label("Connect To Server");

    // Server Host Name
    w_serverHostNameBox = Gtk::Box();
    w_serverHostNameLabel = Gtk::Label("Host Name");
    w_serverHostNameEntry = Gtk::Entry();

    w_serverHostNameBox.append(w_serverHostNameLabel);
    w_serverHostNameBox.append(w_serverHostNameEntry);

    // Server Port
    w_serverPortBox = Gtk::Box();
    w_serverPortLabel = Gtk::Label("Port");
    w_serverPortEntry = Gtk::Entry();

    w_serverPortBox.append(w_serverPortLabel);
    w_serverPortBox.append(w_serverPortEntry);

    // Button
    w_connectButton = Gtk::Button("Connect");

    // Connect Signals
    w_connectButton.signal_clicked().connect(sigc::mem_fun(*this, &ConnectToServerView::S_ConnectButtonPress));

    // Append
    append(w_header);
    append(w_serverHostNameBox);
    append(w_serverPortBox);
    append(w_connectButton);
}

void ConnectToServerView::S_ConnectButtonPress() {
    printf("Test\n");
}
