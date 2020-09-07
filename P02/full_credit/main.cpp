#include <iostream>
#include <cstdlib>

int main(){
    srand(time(NULL));
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
    while (roll_count < roll_freq){
        std::cout << "Roll "<<roll_count<<":";
        int sum=0;
        for (int die=0;die<dice_num;++die){
            int rand_int = rand()%face_num+1; // returns random int between 1 and number of faces in the die
            std::cout << "\t"<<rand_int;
            sum+= rand_int;
        }
        std::cout<< " Sum:"<<sum<<std::endl;
        roll_count+=1;
    }


    return 1;
}