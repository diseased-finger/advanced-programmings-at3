//
// Created by jedsaxon on 6/11/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT3_SERVERINTERFACEVIEW_H
#define ADVANCED_PROGRAMMINGS_AT3_SERVERINTERFACEVIEW_H


#include <gtkmm/box.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/listview.h>
#include <gtkmm/stringlist.h>
#include "../ProgramWindow.h"
#include "../net/Server.h"

class ServerInterfaceView : public Gtk::Box {
private:
    Server* server;

    ProgramWindow* window;
    Gtk::ScrolledWindow* messagesScrollView;
    Gtk::Box* messagesList;
public:
    explicit ServerInterfaceView(ProgramWindow* _window);
    ~ServerInterfaceView();

    void S_GoBackButtonClick();
    void S_AppendTextButton();

    void StartServer();

    void StopServer();

    void ConstructUI();
};


#endif //ADVANCED_PROGRAMMINGS_AT3_SERVERINTERFACEVIEW_H
