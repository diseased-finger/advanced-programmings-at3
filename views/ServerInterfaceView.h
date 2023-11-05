//
// Created by jedsaxon on 6/11/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT3_SERVERINTERFACEVIEW_H
#define ADVANCED_PROGRAMMINGS_AT3_SERVERINTERFACEVIEW_H


#include <gtkmm/box.h>
#include "../ProgramWindow.h"

class ServerInterfaceView : public Gtk::Box {
private:
    ProgramWindow* window;
public:
    explicit ServerInterfaceView(ProgramWindow* window);
};


#endif //ADVANCED_PROGRAMMINGS_AT3_SERVERINTERFACEVIEW_H
