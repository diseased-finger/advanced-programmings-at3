//
// Created by jedsaxon on 6/11/23.
//

#include "ClientInterfaceView.h"
#include "../net/Client.h"
#include "../net/exceptions/GeneralNetError.h"

ClientInterfaceView::ClientInterfaceView(ProgramWindow* window) {
    // Attributes
    this->window = window;
    set_orientation(Gtk::Orientation::VERTICAL);

    // Header
    w_header = Gtk::Label("Connect To Server");
    w_notificationMsg = new Gtk::Label("Errors will show here");

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

    // Messages
    w_msgBox = Gtk::Box();
    w_msgBox.set_orientation(Gtk::Orientation::HORIZONTAL);

    w_msgEntry = new Gtk::Entry();
    w_sendButton = Gtk::Button("Send");

    w_msgBox.append(*w_msgEntry);
    w_msgBox.append(w_sendButton);

    // Button
    w_goBackButton = new Gtk::Button("Go Back");

    // Connect Signals
    w_goBackButton->signal_clicked().connect(sigc::mem_fun(*this, &ClientInterfaceView::S_GoBackButtonPress));
    w_sendButton.signal_clicked().connect(sigc::mem_fun(*this, &ClientInterfaceView::S_ConnectButtonPress));

    // Append
    append(w_header);
    append(*w_notificationMsg);
    append(w_serverHostNameBox);
    append(w_serverPortBox);
    append(w_msgBox);
    append(*w_goBackButton);
}

void ClientInterfaceView::S_GoBackButtonPress() {
    window->NavigateToHomeView();
}

void ClientInterfaceView::S_ConnectButtonPress() {
    // Get hostname, port, and message
    std::string hostname = w_serverHostNameEntry->get_text();

    std::string rawPort = w_serverPortEntry->get_text();
    int port = std::stoi(rawPort);

    std::string message = w_msgEntry->get_text();

    // Prepare Client and send msg
    printf("[Client] Preparing Client Connection\n");
    Client c = Client(hostname, port);

    try {
        c.SendMessage(message);
    } catch (GeneralNetError e) {
        std::string error = "[Error] " + e.GetMessage();
        printf("%s\n", error.c_str());
        w_notificationMsg->set_text(error);
        return;
    }

    w_notificationMsg->set_text("Sent Message");
}
