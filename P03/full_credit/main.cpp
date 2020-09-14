#include "match.h"
int main(){
    int num_tiles;
    int tile1, tile2;
    int health=3;
    std::cout<<std::endl<<"Number of tiles? ";
    std::cin>>num_tiles;
    Board matching_words{num_tiles};
    
    std::cout<<std::endl<<matching_words.to_string();
    while (matching_words.solved()==false){
        std::cout<<std::endl<<"Guess 3, select 2 unmatched tiles: ";
        std::cin>>tile1>>tile2;
        std::cout<<std::endl<<matching_words.attempt(tile1,tile2);
        std::cout<<std::endl<<matching_words.to_string();

    }
    
    
    return 0;
}