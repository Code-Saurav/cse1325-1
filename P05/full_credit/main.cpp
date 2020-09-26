#include "gate.h"

int main(){
    Gate *ab,*cd,*abcd;
    And a_b,c_d;
    Or ab_cd;
    ab=&a_b;
    cd=&c_d;
    abcd=&ab_cd;
    ab->connect(*abcd,PINONE);
    cd->connect(*abcd,PINTWO);
    abcd->input(PINONE,SIGNALZERO);
    abcd->input(PINTWO, SIGNALZERO);
    std::cout<<std::endl<<abcd->output()<<std::endl;

}