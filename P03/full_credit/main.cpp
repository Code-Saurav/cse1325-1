#include <iostream>
#include <vector>
#include <string>
#include "match.h"
int main(){
    int num_tiles;
    int tile1, tile2;
    int health=3;
    std::cout<<std::endl<<"Number of tiles? ";
    std::cin>>num_tiles;
    Board matching_words{num_tiles};
    
    while (matching_words.solved()==false){
        std::cout<<std::endl<<matching_words.to_string();
        std::cout<<std::endl<<"Guess 3, select 2 unmatched tiles: ";
        std::cin>>tile1>>tile2;
        std::cout<<std::endl<<matching_words.attempt(tile1,tile2);
        tile1=-1;
        tile2=-1;
    }
    
    
    return 0;
}