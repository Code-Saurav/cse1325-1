#ifndef _GATE__H

#define _GATE__H

#include "data.cpp"

#define PINONE 1
#define PINTWO 2

#define SIGNALZERO 0
#define SIGNALONE 1

class Gate{
    public:
        Gate();
        void connect(Gate& gate, Pin input_pin);
        void input(Pin pin, Signal signal);
        Signal input(Pin pin);
        virtual Signal output()=0;
    private:
        Gate* _to_gate;
        Pin _to_pin;
    protected:
        Signal _input1;
        Signal _input2;
    
};
class And: public Gate{
    public:
        Signal output() override;
};
class Or: public Gate{
    public:
        Signal output() override;
};

#endif