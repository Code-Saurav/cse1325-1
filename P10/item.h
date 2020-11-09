#ifndef __ITEM_H
#define __ITEM_H
#include "store.h"
#include "tool.h"
#include "mulch.h"
#include <fstream>
class Item{
    private:
        Product* _product;
        int _quantity;
    public:
        double subtotal();
        Item(Product& product, int quantity);
        Item(std::istream& ist);
        ~Item(); //destructor
        Item& operator=(const Item &rhs); //copy assignment operator : MAINTAIN RULE OF THREE
        void save(std::ostream& ost); 
        int quantity();
};
#endif