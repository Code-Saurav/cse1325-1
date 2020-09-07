#include "die.h"
int main(){
    int dice_num, face_num, roll_freq;
    /* 
        dice_num= number of dices
        face_num = number of faces
        roll_freq = number of times to roll
    */
    std::cout << "Number of dice? ";
    std::cin >> dice_num;
    std::cout << std::endl<<"Number of faces per die? ";
    std::cin >> face_num;
    std::cout << std::endl<< "Number of rolls? ";
    std::cin >> roll_freq;
    int roll_count=0;
    std::cout<<std::endl;
    Die d(face_num);
    while (roll_count < roll_freq){
        std::cout << "Roll "<<roll_count<<":";
        int sum=0;
        for (int die=0;die<dice_num;++die){  
            d.roll();
            int val=d.value();
            sum+=val;
            std::cout<<val<<" ";
        }
        std::cout<< " Sum:"<<sum<<std::endl;
        roll_count+=1;
    }
    return 1;
}