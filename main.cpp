#include <iostream>
#include "ProgramWindow.h"
#include <gtkmm.h>

int main(int argc, char **argv) {
    // Start logs just in case
    std::cout << "--- LOGS ---" << std::endl;

    // Create Application
    auto app = Gtk::Application::create("org.gtkmm.examples.base");

    // Run the program
    return app->make_window_and_run<ProgramWindow>(argc, argv);
}
