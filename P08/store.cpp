#include "store.h"
#include <typeinfo>
Store::Store(std::string name) : _name{name} { }
Store::Store(std::istream& ist){
    std::string store_name;
    getline(ist,store_name,'\n');
    
    int size_of_product;
    ist>>size_of_product;
    
    std::cout<<store_name<<std::endl<<size_of_product<<std::endl;
    int price =0;
    std::string line;
    if(ist.good()){
        while (getline(ist,line)){
     
            if (line.compare("tool")){
                _products.push_back(new Tool{ist});
            } else if (line.compare("plant")){
                _products.push_back(new  Plant{ist});
                
            } else if (line.compare("mulch")){
                _products.push_back(new  Mulch{ist});
                
            } else{
                throw std::out_of_range("Invalid type");
            }
        }
    }
    
}
// (new Tool{name, price, description}));

void Store::save(std::ostream& ost){
    int j=0;
    ost<<_name<<'\n'<<products()<<'\n';
    while (j<products()){
        _products[j]->save(ost);
        j++;
    }
    ost<<std::endl;
}
void Store::add_product(const Tool& product) {_products.push_back(new Tool{product});}
void Store::add_product(const Plant& product) {_products.push_back(new Plant{product});}
void Store::add_product(const Mulch& product) {_products.push_back(new Mulch{product});}
int Store::products() {return _products.size();}
const Product& Store:: product(int index) {return *_products.at(index);}

