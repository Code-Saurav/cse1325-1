#ifndef __ENTRYDIALOG_H
#define __ENTRYDIALOG_H
#include <gtkmm>
#include <iostream>
class EntryDialog: public Gtk::MessageDialog{
    public:
        EntryDialog(Gtk::Window& parent, Glib::ustring message, bool use_markup, Gtk::MessageType type, Gtk::ButtonsType buttons);
        void set_text(Glib::ustring text);
        Glib::ustring get_text();
        Mainwin();
        virtual ~Mainwin();
}
#endif