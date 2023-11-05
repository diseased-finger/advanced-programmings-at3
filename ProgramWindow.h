//
// Created by jedsaxon on 6/11/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT3_PROGRAMWINDOW_H
#define ADVANCED_PROGRAMMINGS_AT3_PROGRAMWINDOW_H


#include <gtkmm/window.h>

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>

class ProgramWindow : public Gtk::Window {
private:
    Gtk::Box w_box;
    Gtk::Label w_label;
    Gtk::Button w_connectToServerButton;
    Gtk::Button w_createServerButton;
public:
    ProgramWindow();
};


#endif //ADVANCED_PROGRAMMINGS_AT3_PROGRAMWINDOW_H
