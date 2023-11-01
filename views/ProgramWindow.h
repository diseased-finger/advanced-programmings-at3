//
// Created by jedsaxon on 2/11/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT3_PROGRAMWINDOW_H
#define ADVANCED_PROGRAMMINGS_AT3_PROGRAMWINDOW_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>

class ProgramWindow : public Gtk::Window {
public:
    ProgramWindow();
protected:
    // Widgets
    Gtk::Button button_w;
    Gtk::Box box_w;

    // Signals
    void OnButtonClick_S();
};

#endif //ADVANCED_PROGRAMMINGS_AT3_PROGRAMWINDOW_H
