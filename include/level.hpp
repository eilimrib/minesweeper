#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "tile.hpp"

class Level {
    public:
        Level();
        void generate(int rows, int cols, int bomb_count);
        void draw(sf::RenderWindow &window);
        bool checkWin();
        inline std::vector<std::vector<Tile>> getLevel() { return lvl; }
        void inline updateLevel(std::vector<std::vector<Tile>> level) { lvl = level; }
        void inline addFlag() { totalFlags++; }
        void inline addCorrectFlag() { correctFlags++; }
        void inline removeCorrectFlag() { correctFlags--; }
        void inline removeFlag() { totalFlags--; }
    private:
        void initIntRect();
        int totalFlags;
        int correctFlags;
        std::vector<std::vector<Tile>> lvl;

        sf::Texture tileSheet;
        sf::Sprite sprite;

        sf::IntRect hidden;
        sf::IntRect blank;
        sf::IntRect bomb;
        sf::IntRect flag;
        sf::IntRect one;
        sf::IntRect two;
        sf::IntRect three;
        sf::IntRect four;
};
