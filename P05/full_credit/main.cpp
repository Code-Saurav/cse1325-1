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
    std::cout<<"A B C D  Q"<<std::endl;
    std::cout<<"= = = =  ="<<std::endl;
    for (int i=0;i<2;++i){
        for (int j=0;j<2;++j){
            for (int k=0;k<2;++k){
                for (int l=0;l<2;++l){
                    ab->input(PINONE,i%2);
                    ab->input(PINTWO,j%2);
                    cd->input(PINONE,k%2);
                    cd->input(PINTWO,l%2);
                    std::cout<<std::endl<<ab->input(PINONE)<<" ";
                    std::cout<<ab->input(PINTWO)<<" ";
                    std::cout<<cd->input(PINONE)<<" ";
                    std::cout<<cd->input(PINTWO)<<"  ";
                    std::cout<<abcd->output()<<std::endl;
                }
            }
        }
    }

}