#include "match.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>

std::vector<std::string> words {
"bang", "beam", "bear", "cafe", "came",
"cold", "come", "cool", "date", "diet",
"door", "doth", "echo", "exes", "exit",
"face", "fame", "feed", "fire", "five",
"four", "free", "frog", "from", "game",
"goes", "good", "grit", "have", "heal",
"hear", "here", "hide", "hole", "home",
"hope", "huge", "keep", "kill", "lace",
"lame", "leek", "life", "live", "maps",
"mass", "mate", "maze", "move", "near",
"need", "nine", "once", "quit", "ques",
"race", "read", "reed", "reef", "rice",
"roof", "sins", "stay", "tame", "teen",
"tens", "tide", "tied", "tree", "twin",
"zero", "zips",
};

Board::Board(int tiles){
    std::srand (unsigned (std::time(0)));
    std::random_shuffle(words.begin(),words.end());
    for (int i=0; i<tiles/2;++i){
        Tile tile_word{words[i]};
        _tiles.push_back(tile_word);
        _tiles.push_back(tile_word);
    }
    std::random_shuffle(_tiles.begin(),_tiles.end());
}
std::string Board::attempt(int tile1,int tile2){
    Tile tile_one=_tiles[tile1];
    Tile tile_two=_tiles[tile2];
    if (tile_one.match(tile_two)==true){
        return tile_one.word()+" "+"Matches"+" "+tile_two.word();
    }else {
        return tile_one.word()+" "+tile_two.word();
    };
}
bool Board::solved(){
    bool returnVal;
    for (int i=0; i<_tiles.size();++i){
        if (_tiles[i].matched()==true){
            returnVal=true;
        } else{
            return false;
        }
        return returnVal;
    }
}
std::string Board::to_string(){
    
}