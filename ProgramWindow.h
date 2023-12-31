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
    Gtk::Box* current{};
    Gtk::Box* homeView{};
    Gtk::Box* connectToServerView{};
    Gtk::Box* clientInterfaceView{};
    Gtk::Box* serverInterfaceView{};
    void NavigateTo(Gtk::Box* b);
public:
    ProgramWindow();
    void NavigateToHomeView();
    void NavigateToServerInterfaceView();
    void NavigateToClientInterfaceView();
    void NavigateToConnectToServerView();
};


#endif //ADVANCED_PROGRAMMINGS_AT3_PROGRAMWINDOW_H
