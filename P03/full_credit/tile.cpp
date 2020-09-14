#include <iostream>
#include "match.h"

int Tile::_width=-1;
Tile::Tile(std::string word):_word{word},_matched{false}{
    if (_word.length()>_width){
        _width=_word.length();
        _blank=' ';
        for (int i=0;i<_width;++i){
            _blank=_blank+"-";
        }
    }
};
bool Tile::match(Tile& tile){
    if (_word==tile._word){
        tile._matched=true;
        _matched=true;
    }
    return _matched;
};

std::string Tile::word(){
    return _word;
}

bool Tile::matched(){
    return _matched;
}

int Tile::width(){
    return _width;
}

std::string Tile::to_string(){
    if (_matched==true){
        return _word;
    } else {
        return _blank;
    }
}


