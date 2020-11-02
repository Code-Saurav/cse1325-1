#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "store.h"
#include "customer.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_new_store_click();     // Create a new store
        void on_save_click();          // Save the Game
        void on_save_as_click();       // Save as game
        void on_open_click();          // Open the game
        void on_new_tool_click();      // Create a new tool product
        void on_new_plant_click();     // Create a new plant product
        void on_new_mulch_click();     // Create a new mulch product
        void on_view_products_click(); // Update the display
        void on_new_customer_click();  // Observer for our new customers button
        void on_view_customer_click(); // Display the customer 
        void on_about_click();         // Click About Game
        void on_quit_click();          // Exit the game

        // Gtk::Grid m_Grid;
        // Gtk::Label name_entry_label;
        // Gtk::Entry name_entry;

        // Gtk::Label email_entry_label;
        // Gtk::Entry email_entry;

        // Gtk::Label phone_entry_label;
        // Gtk::Entry phone_entry;

    private:
        int get_int(std::string prompt);
        double get_double(std::string prompt);
        std::string get_string(std::string prompt);
        std::string filename;
        Store* store;               // The currently active store
        Gtk::Label* display;        // Status message display
};
#endif 

