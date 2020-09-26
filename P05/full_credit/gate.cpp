#include "gate.h"

Gate::Gate(){};
void Gate::connect(Gate& gate, Pin input_pin){
    _to_gate=&gate;
    _to_pin=input_pin;
}
Signal Gate::input(Pin pin){
    if (pin==pin_one) return _input1;
    if (pin==pin_two) return _input2;
}
void Gate::input (Pin pin, Signal signal){
    if (pin==pin_one) _input1=signal;
    if (pin==pin_two) _input2=signal;
    Signal output=this->output();
    if (_to_gate!=NULL){
        _to_gate->input(_to_pin,output);
    }
}

Signal And::output(){
    Signal output;
    output = (Signal)(_input1&&_input2);
    return output;
}
Signal Or::output(){
    Signal output;
    output = (Signal)(_input1||_input2);
    return output;
}
