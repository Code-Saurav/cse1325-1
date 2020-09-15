#include "match.h"

std::string Tile::_blank{"----"};
Tile::Tile(std::string word):_word{word},_matched{false}{
    if (_word.length()>_width){
        _width=_word.length();
        _blank=' ';
        for (int i=0;i<_width;++i){
            _blank=_blank+"-";
        }
    }
};
int Tile::_width{-1};
bool Tile::match(Tile& tile){
    if (*this==tile){
        tile._matched=true;
        _matched=true;
    }
    return _matched;
};
bool Tile::operator==(const Tile& tile1) const {
    return (_word==tile1._word);
}

std::string Tile::word(){
    return _word;
}

bool Tile::matched(){
    return _matched;
}

int Tile::width(){
    return _width;
}
std::ostream& operator<<(std::ostream& ost, const Tile& tile){
    if (tile._matched==true){
        ost<< tile._word;
    } else{
        ost<< tile._blank;
    }
    return ost;
}

