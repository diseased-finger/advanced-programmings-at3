//
// Created by jedsaxon on 6/11/23.
//

#include <gtkmm/singleselection.h>
#include "ServerInterfaceView.h"
#include "../net/Server.h"
#include "../net/exceptions/ListenError.h"

ServerInterfaceView::ServerInterfaceView(ProgramWindow *_window) : window(_window) {
    ConstructUI();
    StartServer();
}

ServerInterfaceView::~ServerInterfaceView() {
    StopServer();
    delete server;
}

void ServerInterfaceView::ConstructUI() {
    set_orientation(Gtk::Orientation::VERTICAL);

    // Create Back/Append Buttons
    Gtk::Button backButton = Gtk::Button("Go Back");
    backButton.signal_clicked().connect(sigc::mem_fun(*this, &ServerInterfaceView::S_GoBackButtonClick));

    Gtk::Button appendItemButton = Gtk::Button("Add Something");
    appendItemButton.signal_clicked().connect(sigc::mem_fun(*this, &ServerInterfaceView::S_AppendTextButton));

    // Create Messages Scrolled View
    messagesList = new Box();
    messagesList->set_orientation(Gtk::Orientation::VERTICAL);

    messagesScrollView = new Gtk::ScrolledWindow();
    messagesScrollView->set_child(*messagesList);
    messagesScrollView->set_min_content_height(50);

    append(backButton);
    append(appendItemButton);
    append(*messagesScrollView);

    ServerInterfaceView::window = window;
}

void ServerInterfaceView::StartServer() {
    printf("Hi\n");
    server = new Server(10000);

    try {
        server->Serve(true);
    } catch (ListenError e) {
        printf("Error During Serve: %s\n", e.GetMessage().c_str());
        return;
    }
}

void ServerInterfaceView::StopServer() {
    server->Stop();
}

void ServerInterfaceView::S_GoBackButtonClick() {
    this->window->NavigateToHomeView();
}

void ServerInterfaceView::S_AppendTextButton() {
    Gtk::Label l = Gtk::Label("Something");
    messagesList->append(l);
}
