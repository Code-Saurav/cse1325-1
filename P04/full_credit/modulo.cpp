#include "modulo.h"

Modulo::Modulo(int modulo, int value, int offset):_value{value},_modulo{modulo},_offset{offset}{
};

int Modulo::value(){
    return _value;
}
void Modulo::set_nmsd(Modulo *nmsd){
    _nmsd= nmsd;
}

Modulo& Modulo::operator+=(int rhs){
    this->_value=this->_value+rhs;
    if (this->_value>=(this->_modulo+this->_offset)){
        this->_value=(this->_value)%(this->_modulo);
        if (this->_nmsd!=NULL){
            _nmsd->operator+=(1); //recrusive call to update it's next most significant pointer
        }
    }
    return *this;
}
Modulo Modulo::operator+(int rhs){
    Modulo modulo {*this};
    modulo._value=modulo._value+rhs;
    if (modulo._value>=modulo._modulo){
        modulo._value=(modulo._value)%modulo._modulo;
        if (modulo._nmsd!=NULL){
            modulo._nmsd->operator+=(1);
            // modulo._nmsd->_value=(modulo._nmsd->_value)%(modulo._nmsd->_modulo);
        }
    }
    return modulo;
}
Modulo& Modulo::operator++(){ //preincrement
    this->_value=(this->_value+1);

    if (this->_value>=this->_modulo){
        this->_value=(this->_value)%this->_modulo;
        if (this->_nmsd!=NULL){
            this->_nmsd->_value=(this->_nmsd->_value)%(this->_nmsd->_modulo);
            
            _nmsd->operator+=(1);
        }
    }
    return *this;
}
Modulo Modulo::operator++(int ignored){ //post increment
    Modulo modulo{*this};
    ++*this;
    return modulo;
}



int Modulo::compare(const int rhs){
    int i=0; 
    if (rhs==_value) i+=1; //if _value==_rhs i=1
    if (rhs<_value) i+=3; //if rhs<=_value -> i=4
    if (_value>rhs) i+=5; //if _value>=rhs -> i=6
    //to prevent collision: chose odd number because their sum will be even
    return i; 
    
}
std::ostream& operator<<(std::ostream& ost, const Modulo& m){

    ost<< m._value;

    return ost;
}
std::istream& operator>>(std::istream& ost, Modulo& m){
    
    m._value=(m._value-m._offset)%(m._modulo);
    ost >> m._value;
    return ost; 
}

