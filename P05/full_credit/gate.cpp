#include "gate.h"
Gate::Gate(){
    _input1=SIGNALZERO; 
    _input2=SIGNALZERO;
};
void Gate::connect(Gate& gate, Pin input_pin){
    _to_gate=&gate;
    _to_pin=input_pin;
}
Signal Gate::input(Pin pin){
    if (pin==PINONE) {
        return _input1;
    }
    else if (pin==PINTWO){
        return _input2;
    }
    else{
        std::cerr<< "Invalid Pin Number";
        return 0;
    }
    
}
void Gate::input (Pin pin, Signal signal){
    if (pin==PINTWO || pin==PINONE){
        if (pin==PINONE){
            _input1=signal;
        } else {
            _input2=signal;
        } 
        Signal output=this->output();
        if (_to_gate!=NULL){
            _to_gate->input(_to_pin,output);
        }
    }
}

Signal And::output(){
    Signal output;
    output = _input1&&_input2;
    return output;
}
Signal Or::output(){
    Signal output;
    output =_input1||_input2;
    return output;
}
