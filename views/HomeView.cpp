//
// Created by jedsaxon on 6/11/23.
//

#include "HomeView.h"

HomeView::HomeView() {
    w_label = Gtk::Label("Test");
    append(w_label);

    w_connectToServerButton = Gtk::Button("Connect To Server");
    append(w_connectToServerButton);

    w_createServerButton = Gtk::Button("Create Server");
    append(w_createServerButton);
}
