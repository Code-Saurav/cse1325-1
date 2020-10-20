#include "mainwin.h"
#include <iostream>

Mainwin::Mainwin(): Store{nullptr}{
    set_default_size(400,200);
    set_title("Manga Manager");
    Gtk::Box *vbox = Gtk::manage(new GtK::Vbox);
    add(*vbox);
    Gtk::Menubar *menubar = Gtk::manage(new Gtk::Menubar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK,0);

    //FILE
    //creating a file menu and adding to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage (new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //Adding quit 
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //creating a insert menu and adding to the menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*tool);

    //adding tool
    Gtk::MenuItem *menuitem_tool = Gtk::manage(new Gtk::MenuItem("_Tool",true));
    menuitem_tool->signal_activate().connect([this]{this->on_new_tool_click()});
    insertmenu->append(*menuitem_tool);
    //adding plant
    Gtk::MenuItem *menuitem_plant = Gtk::manage(new Gtk::MenuItem("_Plant",true));
    menuitem_plant->signal_activate().connect([this]{this->on_new_plant_click()});
    insertmenu->append(*menuitem_plant);
    //adding Mulch
    Gtk::MenuItem *menuitem_mulch= Gtk::manage(new Gtk::MenuItem("_Mulch",true));
    menuitem_mulch->signal_activate().connect([this]{this->on_new_mulch_clic()});
    insertmenu->append(*menuitem_mulch);
}

std::string Mainwin::get_string(std::string prompt) {
    std::string s;
    std::cout << prompt;
    std::getline(std::cin, s);
    return s;
}

double Mainwin::get_double(std::string prompt) {
    while(true) {
        try {
            return std::stod(get_string(prompt));
        } catch(std::exception& e) {
            std::cerr << "ERROR: " << e.what() << std::endl;
        }
    }
}

int Mainwin::get_int(std::string prompt) {
    while(true) {
        try {
            return std::stoi(get_string(prompt));
        } catch(std::exception& e) {
            std::cerr << "ERROR: " << e.what() << std::endl;
        }
    }
}
