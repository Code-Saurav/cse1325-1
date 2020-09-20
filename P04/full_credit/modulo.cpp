#include "modulo.h"

Modulo::Modulo(int modulo, int value, int offset):_value{value},_modulo{modulo},_offset{offset}{};

int Modulo::value(){
    
    return _value;
}
void Modulo::set_nmsd(Modulo *nmsd){
    _nmsd= nmsd;
}

Modulo& Modulo::operator+=(int rhs){
    _value=_value+rhs;
    if (_value>=_modulo){
        _value=(_value)%_modulo;
        _nmsd->_value=(_nmsd->_value)%(_nmsd->_modulo);
        _nmsd->_value++;
    }
    return *this;
}
Modulo Modulo::operator+(int rhs){
    _value=_value+rhs;
    if (_value>=_modulo){
        _value=(_value)%_modulo;
        _nmsd->_value=(_nmsd->_value)%(_nmsd->_modulo);
        _nmsd->_value++;
    }
    return *this;
}
Modulo Modulo::operator++(int ignored){
    _value=_value+1;
    if (_value>=_modulo){
        _value=(_value)%_modulo;
        _nmsd->_value=(_nmsd->_value)%(_nmsd->_modulo);
        _nmsd->_value++;
    }
    return *this;
}
Modulo& Modulo::operator++(){
    Modulo *temp{this};
    _value=_value+1;
    if (_value>=_modulo){
        _value=(_value)%(_modulo);
        _nmsd->_value++;
    }
    return *temp;
}

std::ostream& operator<<(std::ostream& ost, const Modulo& m){
    ost<< m._value;
    return ost;
}

int Modulo::compare(const int rhs){
    int i=0; 
    if (rhs==_value) i+=1; //if _value==_rhs i=1
    if (rhs<_value) i+=3; //if rhs<=_value -> i=4
    if (_value>rhs) i+=5; //if _value>=rhs -> i=6
    //to prevent collision: chose odd number because their sum will be even
    return i; 
    
}
std::istream& operator>>(std::istream& ost, Modulo& m){
    
    m._value=(m._value-m._offset)%(m._modulo);
    ost >> m._value;
    return ost; 
}

