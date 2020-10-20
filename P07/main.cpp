#include "mainwin.h"

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "MANGA Manager");
    Mainwin win;
    app->run(win);
}