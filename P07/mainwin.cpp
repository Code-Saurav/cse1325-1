#include "mainwin.h"
#include <iostream>
#include <vector>
#include <string>
#include "entrydialog.h"

Mainwin::Mainwin():store{nullptr} {
    set_default_size(400,200);
    set_title("Manga Manager");
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    //menubar
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
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
    menuitem_insert->set_submenu(*insertmenu);

    //adding tool
    Gtk::MenuItem *menuitem_tool = Gtk::manage(new Gtk::MenuItem("_Tool",true));
    menuitem_tool->signal_activate().connect([this]{this->on_new_tool_click();});
    insertmenu->append(*menuitem_tool);
    //adding plant
    Gtk::MenuItem *menuitem_plant = Gtk::manage(new Gtk::MenuItem("_Plant",true));
    menuitem_plant->signal_activate().connect([this]{this->on_new_plant_click();});
    insertmenu->append(*menuitem_plant);
    //adding Mulch
    Gtk::MenuItem *menuitem_mulch= Gtk::manage(new Gtk::MenuItem("_Mulch",true));
    menuitem_mulch->signal_activate().connect([this]{this->on_new_mulch_click();});
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
    store= new Store("");
    on_view_products_click();
};


void Mainwin::on_new_tool_click(){ 
     std::vector<Product*> products;
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
    store=new Store(new_tool.get_text());
    products.push_back(new Tool(get_string(new_tool.get_text())
        ,get_double(new_tool_price.get_text()),get_string(new_tool_description.get_text())));
    // ,std::stod(new_tool_price.get_text()),new_tool_description.get_text()));
    
};
void Mainwin::on_new_plant_click(){
    std::vector<Product*> products;
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
    store=new Store(new_plant.get_text());
    products.push_back(new Plant(get_string(new_plant.get_text())
        ,get_double(new_plant_price.get_text()),get_string(new_plant_description.get_text()),get_string(new_plant_species.get_text())));
};
void Mainwin::on_new_mulch_click(){
    std::vector<Product*> products;
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
    store=new Store(new_mulch.get_text());
    products.push_back(new Mulch(get_string(new_mulch.get_text())
        ,get_double(new_mulch_price.get_text()),get_string(new_mulch_description.get_text())));
    
};

//for displaying the result;
void Mainwin::on_view_products_click(){
    for (int i=0; i< store->products();i++){
        std::ostringstream oss;
        oss<<store->product(i)<<std::endl;
        display->set_text(oss.str());
    }

};

void Mainwin::on_quit_click() {
    close();
}


std::string Mainwin::get_string(std::string prompt) {
    return prompt;
}

double Mainwin::get_double(std::string prompt) {
    while(true) {
        try {
            return std::stod(get_string(prompt));
        } catch(std::exception& e) {
            display->set_markup(std::string{e.what()});
        }
    }
}

int Mainwin::get_int(std::string prompt) {
    while(true) {
        try {
            return std::stoi(get_string(prompt));
        } catch(std::exception& e) {
            display->set_markup(std::string{e.what()});;
        }
    }
}


