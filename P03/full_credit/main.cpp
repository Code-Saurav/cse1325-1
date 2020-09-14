#include "match.h"
int main(){
    int num_tiles;
    int tile1, tile2;
    int health=3;
    std::cout<<std::endl<<"Number of tiles? ";
    std::cin>>num_tiles;
    Board matching_words{num_tiles};
    int guess_num=0;
    std::cout<<std::endl<<matching_words.to_string();
    while (matching_words.solved()==false){
        guess_num++;
        std::cout<<std::endl<<"Guess "<< guess_num<<", select 2 unmatched tiles: ";
        std::cin>>tile1>>tile2;
        std::cout<<std::endl<<matching_words.attempt(tile1,tile2);
        std::cout<<std::endl<<matching_words.to_string();
    }
    std::cout<<std::endl<<"Congratulations - you won in "<<guess_num<< " number of guesses"<<std::endl;  
    return 0;
}