#include "mainwin.h"

#include "entrydialog.h"

Mainwin::Mainwin() : store{nullptr}, display{new Gtk::Label{}} {

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

    

    //      NEW 
    // Create a new menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New",true));
    menuitem_new->signal_activate().connect([this]{this->on_new_store_click();}); 
    filemenu->append(*menuitem_new);

    // Save 
    // Create a save menu 
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save",true));
    menuitem_save->signal_activate().connect([this]{this->on_save_click();}); 
    filemenu->append(*menuitem_save);

    //Save As
    Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("_Save As",true));
    menuitem_save_as->signal_activate().connect([this]{this->on_save_as_click();}); 
    filemenu->append(*menuitem_save_as);

    //Open
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open",true));
    menuitem_open->signal_activate().connect([this]{this->on_open_click();}); 
    filemenu->append(*menuitem_open);
//Adding quit 
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);


    //              HELP
    // Append Help to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help",true));
    menubar->append(*menuitem_help);
    Gtk::Menu *inserthelp = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*inserthelp);

    //              ABOUT
    // Append About to the About 
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About",true));
    menuitem_about->signal_activate().connect([this]{this->on_about_click();});
    inserthelp->append(*menuitem_about);

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

Mainwin::~Mainwin() { }

void Mainwin::on_new_store_click() {
    delete store;
    std::string store_name = get_string("Please enter your store Name?");
    if (store_name=="") store_name="Untitled";
    store = new Store{store_name};
    on_view_products_click();
}


void Mainwin::on_save_as_click(){
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_manga = Gtk::FileFilter::create();
    filter_manga->set_name("MANGA");
    filter_manga->add_pattern("*.manga");
    dialog.add_filter(filter_manga);

    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("temp.manga");
    
    dialog.add_button("_Cancel",0);
    dialog.add_button("_Save",1);

    int result = dialog.run();

    if (result==1){
        try{
            std::ofstream ofs{dialog.get_filename()};
            filename= dialog.get_filename();
            std::cout<<'\n'<<filename;
            store->save(ofs);

        } catch(std::exception e){
            Gtk::MessageDialog{*this,"Unable to save file"}.run();
        }
        std::cout<<"\nFile has been saved \n";
    }
    std::cout<<filename;
}
void Mainwin::on_save_click(){
    
    std::ofstream ofs{filename};
    std::cout<<filename;
    store->save(ofs);

    
}

void Mainwin::on_open_click(){
    Gtk::FileChooserDialog dialog("Please choose a file", Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_manga = Gtk::FileFilter::create();
    filter_manga->set_name("MANGA File");
    filter_manga->add_pattern("*.manga");
    dialog.add_filter(filter_manga);

    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.manga");

    dialog.add_button("_Cancel",0);
    dialog.add_button("_Open",1);

    int result = dialog.run();

    if (result==1){
        try{
            delete store;
            std::ifstream ifs{dialog.get_filename()};
            filename= dialog.get_filename();
            store = new Store{ifs};
            bool b;
            ifs >> b;
            on_view_products_click();
            
        }catch (std::exception e){
            Gtk::MessageDialog{*this,"Error opening the file"}.run();
        }

    }

std::cout<<"File Opened";
}

void Mainwin::on_about_click(){
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this);
    dialog.set_program_name("About");
    auto logo = Gdk::Pixbuf::create_from_file("main.png");
    dialog.set_logo(logo);
    dialog.set_version("Version 1.2.1");
    dialog.set_copyright("Copyright 2020-2021");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector<Glib::ustring > authors= {"Prabesh Humagain , George F. Rice"};
    dialog.set_authors(authors);
    std::vector<Glib::ustring> artists={"Logo by UTA"};
    dialog.set_artists(artists);
    dialog.run();
}

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




