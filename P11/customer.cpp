#include "customer.h"

Customer::Customer(std::string name, std::string phone, std::string email): _name{name},_phone{phone},_email{email}{};

Customer::Customer(std::istream& ist){
    // std::string temp_name, temp_phone,temp_email;
    std::string temp;
    if (ist.good()) {
        getline(ist,_name);
    } 
    if (ist.good()){
        getline(ist,_phone);
    }
    if (ist.good()){
        getline(ist,_email);
    }
}
void Customer::save(std::ostream& ost){
    ost<<_name<<'\n'<<_phone<<'\n'<<_email<<std::endl;
}
std::ostream& operator<<(std::ostream& ost, const Customer& customer) {
    ost<<customer._name<<" ("<<customer._phone<<", "<<customer._email<<")";
    return ost;
}
