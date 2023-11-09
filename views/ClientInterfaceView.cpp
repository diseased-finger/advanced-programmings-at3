//
// Created by jedsaxon on 6/11/23.
//

#include "ClientInterfaceView.h"

ClientInterfaceView::ClientInterfaceView(ProgramWindow* window) {
    // Attributes
    this->window = window;
    set_orientation(Gtk::Orientation::VERTICAL);

    // Header
    w_header = Gtk::Label("Connect To Server");

    // Server Host Name
    w_serverHostNameBox = Gtk::Box();
    w_serverHostNameLabel = Gtk::Label("Host Name");
    w_serverHostNameEntry = new Gtk::Entry();

    w_serverHostNameBox.append(w_serverHostNameLabel);
    w_serverHostNameBox.append(*w_serverHostNameEntry);

    // Server Port
    w_serverPortBox = Gtk::Box();
    w_serverPortLabel = Gtk::Label("Port");
    w_serverPortEntry = new Gtk::Entry();
    w_serverPortEntry->set_text("10000");

    w_serverPortBox.append(w_serverPortLabel);
    w_serverPortBox.append(*w_serverPortEntry);

    // Button
    w_connectButton = new Gtk::Button("Connect");
    w_goBackButton = new Gtk::Button("Go Back");

    // Connect Signals
    w_goBackButton->signal_clicked().connect(sigc::mem_fun(*this, &ClientInterfaceView::S_GoBackButtonPress));
    w_connectButton->signal_clicked().connect(sigc::mem_fun(*this, &ClientInterfaceView::S_ConnectButtonPress));

    // Append
    append(w_header);
    append(w_serverHostNameBox);
    append(w_serverPortBox);
    append(*w_connectButton);
    append(*w_goBackButton);
}

void ClientInterfaceView::S_GoBackButtonPress() {
    window->NavigateToHomeView();
}

void ClientInterfaceView::S_ConnectButtonPress() {
    std::string hostname = w_serverHostNameEntry->get_text();

    std::string rawPort = w_serverPortEntry->get_text();
    int port = std::stoi(rawPort);

    printf("Hostname Input: %s, Port Input: %i\n", hostname.c_str(), port);
}
