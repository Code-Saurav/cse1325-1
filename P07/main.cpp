// #include "tool.h"
// #include "plant.h"
// #include "mulch.h"

// int main() {
//     Tool tool("Spade", 5.99, "Digs in the dirt");
//     std::cout << tool << std::endl;
//     Plant plant("Clover", 1.59, "It bee sweet!", "T. pratense", Exposure::SUN);
//     std::cout << plant << std::endl;
//     Mulch mulch("Red Cedar Mulch", 6.99, "Smells heavenly!", 2.0, Material::CEDAR);
//     std::cout << mulch << std::endl;
// }

// }
#include <gtkmm.h>
#include <iostream>
class Mainwin : public Gtk::Window {
 public:
 Mainwin(); // Adds widgets and signals on launch
 virtual ~Mainwin(); // Deletes unmanaged widgets on window close
 protected:
 void on_button_clicked();
 Gtk::Button button; //button
};
Mainwin::Mainwin(): button{"Hello World"} { // Constructor adds widgets and signals
    set_border_width(10);
 // Create a memory-managed Label with centered "Hello, World!" on it
  button.signal_clicked().connect(
      [this] {this->on_button_clicked();}
  );
 add(button);
 button.show();
}
void Mainwin::on_button_clicked(){
    std::cout<<"Hello,world"<<std::endl;
}
Mainwin::~Mainwin() { } // Always declare a virtual destructor


int main(int argc, char* argv[]) { // Main is predictable - make an app
 auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.hello");
 Mainwin win; // Instance the Window
 return app->run(win); // Tell the app to run the window
}