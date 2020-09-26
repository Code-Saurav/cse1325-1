#ifndef _GATE__H
#define _GATE__H
class Gate{
    public:
        Gate();
        void connect(Gate& gate, Pin input_pin);
        void input(Pin pin, Signal signal);
        Signal input(Pin pin);
        Signal output();
    private:
        Gate* _to_gate;
        Pin _to_pin;
    protected:
        Signal _input1;
        Signal _input2;
    
}
#endif