#include "item.h"
Item::Item(Product& product, int quantity):_product{ new Product(product)}, _quantity{quantity}{};

Item::~Item(){
    delete _product;
}

Item::Item(std::istream& ist){
    if (ist.good()){
        ist>>_quantity;
        ist.ignore(32768,'\n');
    }
    if (ist.good()){
        std::string line;
        getline(ist,line,'\n');
        if (line=="tool"){
            _product = new Tool{ist};
        } else if (line=="plant"){
            _product = new Plant{ist};
        } else if (line =="mulch") {
            _product=new Mulch{ist};
        } else{}
    }
}

Item& Item::operator=(const Item& rhs){
    if (this == &rhs) return *this;  
    this->_product= rhs._product;
    this->_quantity= rhs._quantity;
    return *this;
}

void Item::save(std::ostream& ost){
    ost<<_quantity<<std::endl;
    _product->save(ost);

}

double Item::subtotal(){
    int price = _product->_price * _quantity;
    return price;
}

int Item::quantity(){
    return _quantity;
}


