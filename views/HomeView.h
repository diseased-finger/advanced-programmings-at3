//
// Created by jedsaxon on 6/11/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT3_HOMEVIEW_H
#define ADVANCED_PROGRAMMINGS_AT3_HOMEVIEW_H


#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>
#include "../ProgramWindow.h"

class HomeView : public Gtk::Box {
private:
    ProgramWindow* window;

    Gtk::Label w_label;
    Gtk::Button w_connectToServerButton;
    Gtk::Button w_createServerButton;

    void S_ConnectToServerButtonClick();
public:
    HomeView(ProgramWindow* window);
};


#endif //ADVANCED_PROGRAMMINGS_AT3_HOMEVIEW_H
