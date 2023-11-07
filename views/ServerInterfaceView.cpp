//
// Created by jedsaxon on 6/11/23.
//

#include <gtkmm/singleselection.h>
#include "ServerInterfaceView.h"
#include "../net/Server.h"
#include "../net/exceptions/ListenError.h"

ServerInterfaceView::ServerInterfaceView(ProgramWindow *window) {
    set_orientation(Gtk::Orientation::VERTICAL);

    // Create Back/Append Buttons
    Gtk::Button backButton = Gtk::Button("Go Back");
    backButton.signal_clicked().connect(sigc::mem_fun(*this, &ServerInterfaceView::S_GoBackButtonClick));

    Gtk::Button appendItemButton = Gtk::Button("Add Something");
    appendItemButton.signal_clicked().connect(sigc::mem_fun(*this, &ServerInterfaceView::S_AppendTextButton));

    // Create Messages Scrolled View
    messagesList = new Gtk::Box();
    messagesList->set_orientation(Gtk::Orientation::VERTICAL);

    messagesScrollView = new Gtk::ScrolledWindow();
    messagesScrollView->set_child(*messagesList);
    messagesScrollView->set_min_content_height(50);

    append(backButton);
    append(appendItemButton);
    append(*messagesScrollView);

    this->window = window;

    // Create Server listening on port 10,000
    Server* s = new Server(10000);

    try {
        s->Initialise(true);
    } catch (SocketError e) {
        printf("Error: %s", e.GetMessage());
        return;
    }

    try {
        s->Serve(true);
    } catch (ListenError e) {
        printf("Error: %s", e.GetMessage());
        return;
    }
}

void ServerInterfaceView::S_GoBackButtonClick() {
    this->window->RouteToHomeView();
}

void ServerInterfaceView::S_AppendTextButton() {
    Gtk::Label l = Gtk::Label("Something");
    messagesList->append(l);
}
