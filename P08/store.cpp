#include "store.h"

Store::Store(std::string name) : _name{name} { }
Store::Store(std::istream& ist){
    std::string store_name;
    int size_of_product;
    getline(ist,store_name,'\n');
    ist>>size_of_product;
    std::cout<<store_name<<std::endl<<size_of_product<<std::endl;
    // ist>>name;
    // std::cout<<name;
    
}

void Store::save(std::ostream& ost){
    int j=0;
    ost<<_name<<'\n'<<products()<<'\n';
    while (j<products()){
        ost<<product(j++)<<'\n';
    }
    ost<<std::endl;
}
void Store::add_product(const Tool& product) {_products.push_back(new Tool{product});}
void Store::add_product(const Plant& product) {_products.push_back(new Plant{product});}
void Store::add_product(const Mulch& product) {_products.push_back(new Mulch{product});}
int Store::products() {return _products.size();}
const Product& Store:: product(int index) {return *_products.at(index);}

