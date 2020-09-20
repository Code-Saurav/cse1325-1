#include "modulo.h"

Modulo::Modulo(int modulo, int value, int offset):_value{value},_modulo{modulo},_offset{offset}{};

int Modulo::value(){
    return _value;
}
void Modulo::set_nmsd(Modulo *nmsd){
    _nmsd= nmsd;
}

Modulo& Modulo::operator+=(int rhs){
    if (_value>=_modulo){
        _value=(_value)%_modulo;
        _nmsd->_value++;
        _nmsd->_value=(_nmsd->_value)%(_nmsd->_modulo);
    }
    _value=_value+rhs;
    return *this;
}
Modulo Modulo::operator+(int rhs){
    _value=_value+rhs;
    if (_value>=_modulo){
        _value=(_value)%_modulo;
        _nmsd->_value++;
    }
    return *this;
}
Modulo Modulo::operator++(int ignored){
    _value=_value+1;
    if (_value>=_modulo){
        _value=(_value)%_modulo;
        _nmsd->_value++;
    }
    return *this;
}
Modulo& Modulo::operator++(){
    Modulo *temp{this};
    _value=_value+1;
    if (_value>=_modulo){
        _value=(_value)%_modulo;
        _nmsd->_value++;
    }
    return *temp;
}

std::ostream& operator<<(std::ostream& ost, const Modulo& m){
    ost<< m._value+m._offset;
    return ost;
}

int Modulo::compare(const int rhs){
    if (rhs<_value) return -1; //less than = -1
    if (_value>rhs) return 1; // greater than = 1
    return 0; // equals =0
    
}
std::istream& operator>>(std::istream& ost, Modulo& m){
    
    ost >> m._value;
    m._value=(m._value-m._offset)%(m._modulo);
    return ost; 
}

