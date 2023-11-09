//
// Created by jedsaxon on 6/11/23.
//


#include "ServerInterfaceView.h"

ServerInterfaceView::ServerInterfaceView(ProgramWindow *_window) : window(_window) {
    ConstructUI();
}

ServerInterfaceView::~ServerInterfaceView() {
    StopServer();
}

void ServerInterfaceView::ConstructUI() {
    set_orientation(Gtk::Orientation::VERTICAL);

    buttonsBox = new Gtk::Box();
    buttonsBox->set_orientation(Gtk::Orientation::HORIZONTAL);

    // Create Back/Append Buttons
    backButton = new Gtk::Button("Go Back");
    backButton->signal_clicked().connect(sigc::mem_fun(*this, &ServerInterfaceView::S_GoBackButtonClick));

    appendItemButton = new Gtk::Button("Add Something");
    appendItemButton->signal_clicked().connect(sigc::mem_fun(*this, &ServerInterfaceView::S_AppendTextButton));

    listenButton = new Gtk::Button("Listen for requests (will freeze app)");
    listenButton->signal_clicked().connect(sigc::mem_fun(*this, &ServerInterfaceView::S_ListenButtonClicked));

    buttonsBox->append(*backButton);
    buttonsBox->append(*appendItemButton);
    buttonsBox->append(*listenButton);

    // Create Messages Scrolled View
    messagesList = new Box();
    messagesList->set_orientation(Gtk::Orientation::VERTICAL);

    messagesScrollView = new Gtk::ScrolledWindow();
    messagesScrollView->set_child(*messagesList);
    messagesScrollView->set_min_content_height(50);

    append(*buttonsBox);
    append(*messagesScrollView);

    ServerInterfaceView::window = window;
}

void ServerInterfaceView::StopServer() {
    server->Stop();
}

void ServerInterfaceView::S_GoBackButtonClick() {
    this->window->NavigateToHomeView();
}

void ServerInterfaceView::S_AppendTextButton() {
    Gtk::Label l = Gtk::Label("[Test] Something");
    messagesList->append(l);
}

void ServerInterfaceView::S_ListenButtonClicked() {
    std::string str = server->Serve(true);

    if (std::empty(str)) {
        str = "[Empty Message]";
    } else {
        str = "[Message from Client] " + str;
    }

    Gtk::Label l = Gtk::Label(str);
    messagesList->append(l);
}