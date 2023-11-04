//
// Created by jedsaxon on 2/11/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT3_MAINVIEW_H
#define ADVANCED_PROGRAMMINGS_AT3_MAINVIEW_H


#include <gtkmm/box.h>
#include <gtkmm/label.h>

class MainView : public Gtk::Box {
private:
    Gtk::Label w_label;
public:
    MainView();
};


#endif //ADVANCED_PROGRAMMINGS_AT3_MAINVIEW_H
