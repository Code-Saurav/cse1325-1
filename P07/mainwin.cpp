#include "mainwin.h"
#include <iostream>
#include <vector>
#include "entrydialog.h"

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
    menuitem_mulch->signal_activate().connect([this]{this->on_new_mulch_click()});
    insertmenu->append(*menuitem_mulch);

    //displaying
    display= Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->add(*display);

    //making everything visible
    vbox->show_all();

    //start a new dialog;
    on_new_store_click();

}

Mainwin::~Mainwin(){};

void Mainwin::on_new_store_click(){
    delete store;
    store= new Store();
    on_view_products_click();
};
void Mainwin::on_new_tool_click(){
    EntryDialog new_tool{*this, "<big>New Product</big>", true};
    new_tool.set_secondary_text("<b>Name</b>?",true);
    new_tool.set_text("");
    new_tool.run();
    EntryDialog new_tool_price{*this, "<big>New Product</big>", true};
    new_tool_price.set_secondary_text("<b>Price</b>?",true);
    new_tool_price.set_text("");
    new_tool_price.run();
    EntryDialog new_tool_description{*this, "<big>New Product</big>", true};
    new_tool_description.set_secondary_text("<b>Description</b>?",true);
    new_tool_description.set_text("");
    new_tool_description.run();

};
void Mainwin::on_new_plant_click(){
    EntryDialog new_plant{*this, "<big>New Product</big>", true};
    new_plant.set_secondary_text("<b>Name</b>?",true);
    new_plant.set_text("");
    new_plant.run();
    EntryDialog new_plant_price{*this, "<big>New Product</big>", true};
    new_plant_price.set_secondary_text("<b>Price</b>?",true);
    new_plant_price.set_text("");
    new_plant_price.run();
    EntryDialog new_plant_description{*this, "<big>New Product</big>", true};
    new_plant_description.set_secondary_text("<b>Description</b>?",true);
    new_plant_description.set_text("");
    new_plant_description.run();
    EntryDialog new_plant_species{*this, "<big>New Product</big>", true};
    new_plant_species.set_secondary_text("<b>Species</b>?",true);
    new_plant_species.set_text("");
    new_plant_species.run();
    EntryDialog new_plant_exposure{*this, "<big>New Product</big>", true};
    new_plant_exposure.set_secondary_text("<b>Exposure? (1) Shade (2) Part Sun (3) Sun</b>?",true);
    new_plant_exposure.set_text("");
    new_plant_exposure.run();
};
void Mainwin::on_new_mulch_click(){
    EntryDialog new_mulch{*this, "<big>New Product</big>", true};
    new_mulch.set_secondary_text("<b>Name</b>?",true);
    new_mulch.set_text("");
    new_mulch.run();
    EntryDialog new_mulch_price{*this, "<big>New Product</big>", true};
    new_mulch_price.set_secondary_text("<b>Price</b>?",true);
    new_mulch_price.set_text("");
    new_mulch_price.run();
    EntryDialog new_mulch_description{*this, "<big>New Product</big>", true};
    new_mulch_description.set_secondary_text("<b>Description</b>?",true);
    new_mulch_description.set_text("");
    new_mulch_description.run();

};
void Mainwin::on_view_products_click(){
    

};

void Mainwin::on_quit_click() {
    close();
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


