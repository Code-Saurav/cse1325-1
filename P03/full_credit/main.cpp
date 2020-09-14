#include <iostream>
#include <vector>
#include <string>
#include "match.h"
int main(){
    int num_tiles;
    int tile1, tile2;
    std::cout<<std::endl<<"Number of tiles? ";
    std::cin>>num_tiles;
    Board matching_words{num_tiles};
    std::cout<<matching_words.to_string();
    std::cout<<std::endl<<"Guess 3, select 2 unmatched tiles: ";
    std::cin>>tile1>>tile2;
    return 0;
}