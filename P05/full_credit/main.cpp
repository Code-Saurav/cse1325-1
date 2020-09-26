#include "gate.h"

int main(){
    Gate *and1,*and2,*or1;
    And and11,and12;
    Or or12;
    and1=&and11;
    and2=&and12;
    or1=&or12;
    and1->connect(*or1,pin_one);
    and2->connect(*or1,pin_two);
    Signal a,b,c,d;
    for (int i=0;i<2;++i){
        a=(i%2==0)? zero_signal:one_signal;
        and1->input(pin_one,a);
        for (int j=0;j<2;++j){
            b=(j%2==0)? zero_signal:one_signal;
            and1->input(pin_two,b);
            for (int k=0;k<2;++k){
                c=(k%2==0)? zero_signal:one_signal;
                and2->input(pin_one,c);
                for (int l=0;l<2;++l){
                    d=(l%2==0)? zero_signal:one_signal;
                    and2->input(pin_two,d);

                }
            }
        }
    }


}