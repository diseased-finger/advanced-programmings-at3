#include <iostream>
#include "views/MainWindow.h"
#include <gtkmm.h>

int main(int argc, char **argv) {
    std::cout << "--- LOGS ---" << std::endl;

    auto app = Gtk::Application::create("org.gtkmm.examples.base");
    return app->make_window_and_run<MainWindow>(argc, argv);
}
