#include <iostream>
#include "views/ProgramWindow.h"
#include "routing/Router.h"
#include "views/MainView.h"
#include <gtkmm.h>

int main(int argc, char **argv) {
    // Start logs just in case
    std::cout << "--- LOGS ---" << std::endl;

    // Create Application
    auto app = Gtk::Application::create("org.gtkmm.examples.base");

    // Initialise Router
    Route** routes = new Route*[1];
    routes[0] = new Route("", new MainView());
    auto *router = new Router(routes, 1, 0);

    return app->make_window_and_run<ProgramWindow>(argc, argv);
}
