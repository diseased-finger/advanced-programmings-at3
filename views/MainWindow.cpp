//
// Created by jedsaxon on 2/11/23.
//

#include "MainWindow.h"
#include <gtkmm.h>
#include <iostream>

MainWindow::MainWindow() :
    button_w("Hello World"),
    box_w()
{
    // Create button which runs OnButtonClick_S when clicked
    button_w.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::OnButtonClick_S));

    set_child(box_w);
    box_w.append(button_w);

    set_title("Advanced Programming - AT3");
    set_default_size(1000, 1000);
}

void MainWindow::OnButtonClick_S() {
    std::cout << "Test" << std::endl;
}
