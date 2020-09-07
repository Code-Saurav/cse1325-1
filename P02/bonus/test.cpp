#include "die.h"
int main(){
    Die d4 (4);
    Die d6 (6);
    Die d8 (8);
    Die d12 (12);
    Die d20 (20);
    std::cout<<std::endl<<"d4:";
    for (int i=0;i<20;i++){
        std::cout<<d4.value()<<" ";
    }
    std::cout<<std::endl<<"d6:";
    for (int i=0;i<20;i++){
        std::cout<<d6.value()<<" ";
    }

    std::cout<<std::endl<<"d8:";
    for (int i=0;i<20;i++){
        std::cout<<d8.value()<<" ";
    }
    std::cout<<std::endl<<"d12:";
    for (int i=0;i<20;i++){
        std::cout<<d12.value()<<" ";
    }
    std::cout<<std::endl<<"d20:";
    for (int i=0;i<20;i++){
        std::cout<<d20.value()<<" ";
    }
    std::cout<<std::endl;
}