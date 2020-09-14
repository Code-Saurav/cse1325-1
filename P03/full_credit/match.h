#ifndef __MATCH_H
#include <vector>
#include <iostream>
#define __MATCH_H
class Tile{
    public:
        Tile(std::string word);
        bool match(Tile& tile);
        std::string word();
        bool matched();
        static int width();
        std::string to_string();
    private:
        std::string _word;
        bool _matched;
        static int _width;
        static std::string _blank;
};
class Board{
    public:
        Board(int tiles); //constructor
        std::string attempt(int tile1, int tile2);
        bool solved();
        std::string to_string();
    private:
        std::vector<Tile> _tiles;
};
#endif