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

class ServerInterfaceView : public Gtk::Box {
private:
    ProgramWindow* window;
    Gtk::ScrolledWindow* messagesScrollView;
    Gtk::Box* messagesList;
public:
    explicit ServerInterfaceView(ProgramWindow* window);
    void S_GoBackButtonClick();
    void S_AppendTextButton();
};


#endif //ADVANCED_PROGRAMMINGS_AT3_SERVERINTERFACEVIEW_H
