#include "customer.h"

Customer::Customer(std::string name, std::string phone, std::string email): _name{name},_phone{phone},_email{email}{};

Customer::Customer(std::istream& ist){
    std::string temp_name, temp_phone,temp_email;
    if (ist.good()){
        getline(ist,temp_name,'\n');
    }
    if (ist.good()){
        getline(ist,temp_phone,'\n');
    }
    if (ist.good()){
        getline(ist,temp_email,'\n');
    }
}
void Customer::save(std::ostream& ost){
    ost<<"__new__customer__"<<'\n';
    ost<<_name<<'\n'<<_phone<<'\n'<<_email<<std::endl;
}
std::ostream& operator<<(std::ostream& ost, const Customer& customer) {
    std::string id="\nName: \t"+customer._name+'\n'+"Phone: \t"+customer._phone+'\n'+"Email: \t"+customer._email;
    ost << id;
    return ost;
}
