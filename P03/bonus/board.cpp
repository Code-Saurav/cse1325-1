#include "match.h"
#include <algorithm>
#include <ctime>
#include <string>

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
    if (_tiles[tile1].match(_tiles[tile2])==true){
        return _tiles[tile1].word()+" "+"MATCHES"+" "+_tiles[tile2].word();
    }else {
        return _tiles[tile1].word()+" "+_tiles[tile2].word();
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
    }
    return returnVal;
}
std::ostream& operator<<(std::ostream& ost, const Board& board){
    std::string string_board;
    for (int i=0;i<(board._tiles).size();i++){
        std::cout<<std::to_string(i)+") ";
        std::cout<<board._tiles[i]<<std::endl;
    }
    ost<< string_board;
    return ost;
}
