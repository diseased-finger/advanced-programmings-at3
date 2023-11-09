//
// Created by jedsaxon on 6/11/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT3_CLIENTINTERFACEVIEW_H
#define ADVANCED_PROGRAMMINGS_AT3_CLIENTINTERFACEVIEW_H


#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>
#include "../ProgramWindow.h"

class ClientInterfaceView : public Gtk::Box {
private:
    ProgramWindow* window;

    Gtk::Label w_header;

    Gtk::Box w_serverHostNameBox;
    Gtk::Label w_serverHostNameLabel;
    Gtk::Entry* w_serverHostNameEntry;

    Gtk::Box w_serverPortBox;
    Gtk::Label w_serverPortLabel;
    Gtk::Entry* w_serverPortEntry;

    Gtk::Button* w_goBackButton;
    Gtk::Button* w_connectButton;
public:
    explicit ClientInterfaceView(ProgramWindow* window);
    void S_GoBackButtonPress();
    void S_ConnectButtonPress();
};


#endif //ADVANCED_PROGRAMMINGS_AT3_CLIENTINTERFACEVIEW_H
