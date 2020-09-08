#include "die.h"
int main(){
    int dice_num, face_num, roll_freq;
    int roll_count=0;
    std::vector <int> die_sum; 
    
    /* 
        dice_num= number of dices
        face_num = number of faces
        roll_freq = number of times to roll
        die_sum = store the die sum in sorted order
    */
    
    
    std::cout << "Number of dice? ";
    std::cin >> dice_num;
    std::cout << std::endl<<"How many faces? ";
    std::cin >> face_num;
    std::cout << std::endl<< "Number of rolls? ";
    std::cin >> roll_freq;
    std::cout<<std::endl;


    Die d(face_num);


    while (roll_count < roll_freq){
        int sum=0;
        for (int die=0;die<dice_num;++die){  
            d.roll();
            int val=d.value();
            sum+=val;
            std::cout<<val<<" ";
        }
        std::cout<< " :="<<sum<<std::endl;
        die_sum.push_back(sum);
        roll_count+=1;
    }
    
    
    std::sort(die_sum.begin(),die_sum.end()); //O(nlgn) to sort the vector
    
    int net_sum=0;
    int num=die_sum[0];
    int mode=num;
    int count=1;
    int count_mode=1;
    net_sum+=num;
    
    for (int i=1;i<die_sum.size();i++){
        if (die_sum[i]==num){
            count+=1;
        }else{
            count=1;
            num=die_sum[i];
        }
        if (count>count_mode){
            count_mode=count;
            mode=die_sum[i];
        }
        std::cout<<die_sum[i]<<" ";
        net_sum+=die_sum[i];
    } //find the sum and the mode in the sorted vector O(n)

    // printing the statistics values 

    std::cout << std::endl<< "Sum = "<< net_sum;  //sum

    std::cout<<std::endl<<"Mean ="<<(double)net_sum/die_sum.size(); //mean

    std::cout<<std::endl<<"Median =";
    if (die_sum.size()%2!=0){
        std::cout<<(double)die_sum[die_sum.size()/2];
    } else{
        std::cout<<(double)(die_sum[(die_sum.size()-1)/2]+die_sum[(die_sum.size()+1)/2])/2.0;
    } //median

    std::cout<<std::endl<<"Mode ="<<mode<< "(appeared "<<count_mode<<" times)"<<std::endl;//mode

    return 1;
}