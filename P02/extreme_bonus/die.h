#include <iostream>
#include <cstdlib>

class Die{
    int _faces; //immutable once the user establishes the dice size
    int _value; // mutable after each roll
    public:
        Die(int faces);
        int faces(); //built to roll the die
        int value();// randomly change the _value
        void roll(); // display the _value 
};