#include "store.h"
#include <typeinfo>
Store::Store(std::string name) : _name{name} { }
Store::Store(std::istream& ist){
    std::string store_name;
    getline(ist,store_name,'\n');
    
    int size_of_product;
    ist>>size_of_product;
    ist.ignore(32768,'\n');
        
    std::cout<<store_name<<std::endl<<size_of_product<<std::endl;
    int price =0;
    std::string line;
    if(ist.good()){
        while (getline(ist,line)){
            Order order{ist};
            _orders.push_back(&order);
        }
    }
    
}
// (new Tool{name, price, description}));

void Store::save(std::ostream& ost){
    int j=0;
    ost<<_name<<'\n'<<products()<<'\n';
    while (j<orders()){
        _orders[j]->save(ost);
        j++;
    }
    ost<<std::endl;
}

std::string Store::name(){
    return _name;
}


void Store::add_product(const Tool& product) {_products.push_back(new Tool{product});}
void Store::add_product(const Plant& product) {_products.push_back(new Plant{product});}
void Store::add_product(const Mulch& product) {_products.push_back(new Mulch{product});}
int Store::products() {return _products.size();}
const Product& Store::product(int index) {return *_products.at(index);}

void Store::add_customer(Customer customer){
    _customers.push_back(new Customer{customer});
}
int Store::customers(){ return _customers.size();}
const Customer& Store::customer(int index){
    return *_customers.at(index);
}

int Store::add_order(Customer& customer){
    Order order{customer};
    _orders.push_back(&order);
    return _orders.size();

}

void Store::add_item(int order_num, Product& product, int quantity){
    Item item{product, quantity};
    Order temp= order(order_num);
    temp.add_item(item);
}

const Order& Store::order(int index){
    return *_orders.at(index);
}


    