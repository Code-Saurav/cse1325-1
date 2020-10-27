#include "mainwin.h"

#include "entrydialog.h"

Mainwin::Mainwin():store{nullptr}, display{new Gtk::Label{}} {
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
    try {
        std::string name = get_string("Please enter name?");
        double price = get_double("Please enter price?");
        std::string description = get_string("Please enter description?");
        store->add_product(*(new Tool{name, price, description}));
        on_view_products_click();
    } catch(std::exception& e) {

    }
    
};
void Mainwin::on_new_plant_click(){
    try {
        std::string name = get_string("Please enter name?");
        double price = get_double("Please enter price?");
        std::string description = get_string("Please enter description?");
        std::string species = get_string("Please enter species?");
        int d = get_double("Please enter exposure? (1) Shade (2) Part Sun (3) Sun");
        Exposure exposure = (d==1) ? Exposure::SHADE : ((d==3) ? Exposure::SUN : Exposure::PARTSUN);
        store->add_product(*(new Plant{name, price, description, species, exposure}));
        on_view_products_click();
    } catch(std::exception& e) {
    }
};
void Mainwin::on_new_mulch_click(){
    try {
        std::string name = get_string("Please enter name?");
        double price = get_double("Please enter price?");
        std::string description = get_string("Please enter Description?");
        int volume = get_int("Please enter Volume in cubic feet?");
        int i = get_int("Please enter Material? (1) Rubber (2) Pine (3) Cedar (4) Hardwood");
        Material material;
        if(i == 1)       {
            material = Material::RUBBER;
        }   else if (i == 2) {
            material = Material::PINE;
        } else if (i == 3) {
            material = Material::CEDAR;
        }else {
            material = Material::HARDWOOD;
        }
        store->add_product(*(new Mulch{name, price, description, volume, material}));
        on_view_products_click();
    } catch(std::exception& e) {
    }
    
};

//for displaying the result;
void Mainwin::on_view_products_click(){
    std::string s ="Your store doesn't have any products for now :(";
    std::string b="Your store has following products\n";
    std::string a="";
    for (int i=0; i< store->products();i++){
        std::ostringstream oss;
        oss<<store->product(i)<<std::endl;
        b+=oss.str();
    }
       if (b=="Your store has following products\n") display->set_text(s) ; else {
           display->set_text(b);
       }       
};

void Mainwin::on_quit_click() {
    close();
}


std::string Mainwin::get_string(std::string prompt) {
    EntryDialog to_enter(*this, "<big>Input Menu</big>", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);
    to_enter.set_secondary_text(prompt, true);
    if(to_enter.run() == Gtk::RESPONSE_CANCEL) throw std::runtime_error{"CANCEL"};
    return to_enter.get_text();
}

double Mainwin::get_double(std::string prompt) {
    while(true) {
        try {
            return std::stod(get_string(prompt));
        } catch(std::exception& e) {
            prompt = e.what();
        }
    }
}

int Mainwin::get_int(std::string prompt) {
    while(true) {
        try {
            return std::stoi(get_string(prompt));
        } catch(std::exception& e) {
            prompt = e.what();
        }
    }
}


