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
        _nmsd->_value++;
    }
    return *this;
}

inline bool Modulo::operator==(const int rhs){
    if (rhs==_value) {return 1;} else {return 0;}
}

inline bool Modulo::operator!=(const int rhs){
    if (rhs!=_value) {return 0;} else {return 1;}
}

inline bool Modulo::operator<(const int rhs){
    if (rhs<_value) {return 1;} else {return 0;}
}

inline bool Modulo::operator<=(const int rhs){
    if (rhs<=_value) {return 1;} else {return 0;}
}

inline bool Modulo::operator>(const int rhs){
    if (rhs>_value) {return 1;} else {return 0;}
}

inline bool Modulo::operator>=(const int rhs){
    if (rhs>_value) {return 1;} else {return 0;}
}

std::ostream& operator<<(std::ostream& ost, const Modulo& m){
    int sum=m._value+m._offset;
    ost<< sum;
    return ost;
}

std::istream& operator>>(std::istream& ost, Modulo& m){
    int input;
    ost >> input;
    input=(input-m._offset)%(m._modulo);
    return ost; 
}

// Modulo Modulo::operator+(int rhs){
//     return 
// }
