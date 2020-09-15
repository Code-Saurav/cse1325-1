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
        friend std::ostream& operator<<(std::ostream& ost, const Tile& tile);
        bool operator==(const Tile& tile1) const;
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
        friend std::ostream& operator<<(std::ostream& ost, const Board& board);

    private:
        std::vector<Tile> _tiles;
};
#endif