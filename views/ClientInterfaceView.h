//
// Created by jedsaxon on 6/11/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT3_CLIENTINTERFACEVIEW_H
#define ADVANCED_PROGRAMMINGS_AT3_CLIENTINTERFACEVIEW_H


#include <gtkmm/box.h>
#include "../ProgramWindow.h"

class ClientInterfaceView : public Gtk::Box {
private:
    ProgramWindow* window;
public:
    explicit ClientInterfaceView(ProgramWindow* window);
};


#endif //ADVANCED_PROGRAMMINGS_AT3_CLIENTINTERFACEVIEW_H
