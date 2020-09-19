#include "modulo.h"

Modulo::Modulo(int modulo, int value, int offset):_value{value},_modulo{modulo},_offset{offset}{};
int Modulo::value(){
    return _value;
}
void Modulo::set_nmsd(Modulo *nmsd){
    if (_value>=_modulo){
        _value=(_value)%_modulo;
        nmsd->_value=nmsd->value()+1;
        
    } 
}