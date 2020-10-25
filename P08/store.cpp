#include "store.h"

Store::Store(std::string name) : _name{name} { }
// Store::Store(std::istream& ist){
//     ist>>_name>>_products[0];
// }

void Store::save(std::ostream& ost){
    int j=0;
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

