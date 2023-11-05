//
// Created by jedsaxon on 6/11/23.
//

#include "ProgramWindow.h"

ProgramWindow::ProgramWindow() {
    // Insert Widgets
    w_box = Gtk::Box();
    set_child(w_box);

    w_label = Gtk::Label("Test");
    w_box.append(w_label);

    w_connectToServerButton = Gtk::Button("Connect To Server");
    w_box.append(w_connectToServerButton);

    w_createServerButton = Gtk::Button("Create Server");
    w_box.append(w_createServerButton);
}
