#include "order.h"

Order::Order(Customer& customer):_customer{customer}{};

Order::Order(std::istream& ist){
    if (ist.good()){
        _customer = Customer(ist);
    }
    std::string line;
    if (ist.good()){
        while (getline(ist,line)){
            _items.push_back(Item(ist));    
            if (line =="__new__customer__") break;
        }
    }
};

void Order::save(std::ostream& ost){
    _customer.save(ost);
    for (auto item: _items){
        item.save(ost);
    }
};

void Order::add_item(Item item){
    _items.push_back(item);
};

double Order::total(){
    double total;
    for (auto temp:_items){
        total=total+temp.subtotal();
    }
    return total;
};
