#include "mainwin.h"

#include "entrydialog.h"
#include "multientrydialog.h"

Mainwin::Mainwin() : store{nullptr}, display{new Gtk::Label{}} {

    set_default_size(800,600);
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

    Gtk::MenuItem *insert_customer = Gtk::manage(new Gtk::MenuItem{"_Customer",true});
    insert_customer->signal_activate().connect([this]{this->on_new_customer_click();}); //yet to be done
    insertmenu->append(*insert_customer);

    Gtk::MenuItem *insert_order =Gtk::manage(new Gtk::MenuItem{"_Order",true});
    insert_order->signal_activate().connect([this]{this->on_new_order_click();});
    insertmenu->append(*insert_order);
   
    //VIEW
    Gtk::MenuItem *view_menu = Gtk::manage(new Gtk::MenuItem{"_View",true});
    menubar->append(*view_menu);
    Gtk::Menu *view = Gtk::manage(new Gtk::Menu()); 
    view_menu->set_submenu(*view);

    //View Customer
    Gtk::MenuItem *customers = Gtk::manage(new Gtk::MenuItem{"_Customers",true});
    customers->signal_activate().connect([this]{this->on_view_customer_click();});
    view->append(*customers);

    //View Products
    Gtk::MenuItem *product = Gtk::manage(new Gtk::MenuItem{"_Products",true});
    product->signal_activate().connect([this]{this->on_view_products_click();});
    view->append(*product);

    Gtk::MenuItem *orders= Gtk::manage(new Gtk::MenuItem{"_Orders",true});
    // orders->signal_activate().connect([this]{this->on_view_orders_click();});
    view->append(*orders);


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


    //TOOLBAR
    Gtk::Toolbar *toolbar= Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    Gtk::ToolButton *new_store = Gtk::manage(new Gtk::ToolButton{Gtk::Stock::NEW});
    new_store->set_tooltip_markup("New Store");
    // new_store->signal_clicked().connect([this]{this->on_new_store_click();});
    toolbar->append(*new_store);


    Gtk::Image *open_store = Gtk::manage(new Gtk::Image{"open.jpeg"});
    Gtk::ToolButton *button1= Gtk::manage(new Gtk::ToolButton(*open_store));
    button1->set_tooltip_markup("Open Store");
    // button1->signal_clicked().connect([this]{this->on_open_click();});
    toolbar->append(*button1);

    Gtk::Image *save_store = Gtk::manage(new Gtk::Image{"save.png"});
    Gtk::ToolButton *button2= Gtk::manage(new Gtk::ToolButton(*save_store));
    button2->set_tooltip_markup("Save Store");
    // button2->signal_clicked().connect([this]{this->on_open_click();});
    toolbar->append(*button2);

    
    Gtk::Image *save_store_as = Gtk::manage(new Gtk::Image{"save_as.png"});
    Gtk::ToolButton *button3= Gtk::manage(new Gtk::ToolButton(*save_store_as));
    button3->set_tooltip_markup("Save As Store");
    // button1->signal_clicked().connect([this]{this->on_open_click();});
    toolbar->append(*button3);

    
    Gtk::Image *insert_customers = Gtk::manage(new Gtk::Image{"customer.png"});
    Gtk::ToolButton *button4= Gtk::manage(new Gtk::ToolButton(*insert_customers));
    button4->set_tooltip_markup("Insert Customer");
    // button1->signal_clicked().connect([this]{this->on_open_click();});
    toolbar->append(*button4);


    Gtk::Image *insert_orders = Gtk::manage(new Gtk::Image{"order.png"});
    Gtk::ToolButton *button5= Gtk::manage(new Gtk::ToolButton(*insert_orders));
    button5->set_tooltip_markup("Insert Order");
    // insert_order->signal_clicked().connect([this]{this->on_new_order_click();});
    toolbar->append(*button5);

    Gtk::Image *insert_tool = Gtk::manage(new Gtk::Image{"tool.png"});
    Gtk::ToolButton *button6= Gtk::manage(new Gtk::ToolButton(*insert_tool));
    button6->set_tooltip_markup("Insert Tool");
    // insert_tool->signal_clicked().connect([this]{this->on_new_tool_click();});
    toolbar->append(*button6);


    Gtk::Image *insert_plant = Gtk::manage(new Gtk::Image{"plant.png"});
    Gtk::ToolButton *button7= Gtk::manage(new Gtk::ToolButton(*insert_plant));
    button7->set_tooltip_markup("Insert Plant");
    // insert_plant->signal_clicked().connect([this]{this->on_new_plant_click();});
    toolbar->append(*button7);

    Gtk::Image *insert_mulchs = Gtk::manage(new Gtk::Image{"mulch.png"});
    Gtk::ToolButton *button8= Gtk::manage(new Gtk::ToolButton(*insert_mulchs));
    button8->set_tooltip_markup("Insert Mulch");
    // insert_mulchs->signal_clicked().connect([this]{this->on_new_mulch_click();});
    toolbar->append(*button8);
    
    Gtk::Image *view_all_customers = Gtk::manage(new Gtk::Image{"view_customer.png"});
    Gtk::ToolButton *button9= Gtk::manage(new Gtk::ToolButton(*view_all_customers));
    button9->set_tooltip_markup("View All Customers");
    // view_all_customers->signal_clicked().connect([this]{this->on_view_customer_click();});
    toolbar->append(*button9);
    
    Gtk::Image *view_all_orders = Gtk::manage(new Gtk::Image{"view_order.png"});
    Gtk::ToolButton *button10= Gtk::manage(new Gtk::ToolButton(*view_all_orders));
    button10->set_tooltip_markup("View Order");
    // view_all_orders->signal_clicked().connect([this]{this->on_view_orders_click();});
    toolbar->append(*button10);
    
    Gtk::Image *view_all_plants = Gtk::manage(new Gtk::Image{"view_plants.png"});
    Gtk::ToolButton *button11= Gtk::manage(new Gtk::ToolButton(*view_all_plants));
    button11->set_tooltip_markup("Open Store");
    // view_all_plants->signal_clicked().connect([this]{this->on_view_products();});
    toolbar->append(*button11);
    
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

std::vector <std::string> Mainwin::get_string_multigrid(){
    MultiEntryDialog to_enter(*this, "<big>Customer Input Menu</big>", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);
    if(to_enter.run() == Gtk::RESPONSE_CANCEL) throw std::runtime_error{"CANCEL"};
    std::vector <std::string> a {to_enter.get_name_text(),to_enter.get_phone_text(),to_enter.get_email_text()};
    return a;
}
void Mainwin::on_new_customer_click(){
    try{
        std::vector <std::string> a = get_string_multigrid();
        std::string name=a[0];
        std::string phone=a[1];
        std::string email=a[2];

        Customer temp(name,phone,email);
        store->add_customer(temp);
        on_view_customer_click();
        
    }catch(std::exception& e){

    }

} 

void Mainwin::on_new_order_click(){
    Gtk::Dialog dialog("Insert Orders", *this);
    Gtk::Grid grid;
    dialog.get_content_area()->add(grid);
    Gtk::Label l_name{"Select the Customer"};
    grid.attach(l_name,0,0,1,1);

    Gtk::ComboBoxText* comboboxtext{Gtk::manage(new Gtk::ComboBoxText{true})};
    grid.attach(*comboboxtext,1,0,1,1);
    int j=0;
    while (j<store->customers()){
        Customer temp = store->customer(j);
        std::ostringstream oss;
        oss<<temp<<std::endl;
        comboboxtext->append(oss.str());
        j++;
    }
    comboboxtext->set_active(1);
    comboboxtext->signal_changed().connect([this]{Gtk::MessageDialog{*this,"Test"}.run();}); 
    dialog.add_button("_Create Order",1);
    dialog.add_button("_Cancel",0);

    dialog.show_all();
    dialog.run();

}

void Mainwin::on_view_orders_click(){
    std::string s ="Your store doesn't have any customer for now :(";
    std::string b="Your store has following orders\n\n-----------------------";
    std::string a="";
    // for (int i=0; i< store->orders();i++){
    //     std::ostringstream oss;
    //     oss<<store->order(i)<<std::endl;
    //     b+=oss.str();
    // }
       if (b=="Your store has following customers\n\n-----------------------") display->set_text(s) ; else {
           display->set_text(b);
       } 
}


//for displaying the customers;
void Mainwin::on_view_customer_click(){
    std::string s ="Your store doesn't have any customer for now :(";
    std::string b="Your store has following customers\n\n-----------------------";
    std::string a="";
    for (int i=0; i< store->customers();i++){
        std::ostringstream oss;
        oss<<store->customer(i)<<std::endl;
        b+=oss.str();
    }
       if (b=="Your store has following customers\n\n-----------------------") display->set_text(s) ; else {
           display->set_text(b);
       } 
}

//for displaying the result;
void Mainwin::on_view_products_click(){
    std::string s ="Your store doesn't have any products for now :(";
    std::string b="Your store has following products\n\n-----------------------\n";
    std::string a="";
    for (int i=0; i< store->products();i++){
        std::ostringstream oss;
        oss<<store->product(i)<<std::endl;
        b+=oss.str();
    }
       if (b=="Your store has following products\n\n-----------------------\n") display->set_text(s) ; else {
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




