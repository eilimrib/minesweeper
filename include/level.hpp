#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "tile.hpp"

class Level {
    public:
        Level();
        void generate(int rows, int cols, int bomb_count);
        void draw(sf::RenderWindow &window);
        inline std::vector<std::vector<Tile>> getLevel() { return level; }
    private:
        void initIntRect();
        std::vector<std::vector<Tile>> level;

        sf::IntRect hidden;
        sf::IntRect blank;
        sf::IntRect bomb;
        sf::IntRect flag;
        sf::IntRect one;
        sf::IntRect two;
        sf::IntRect three;
        sf::IntRect four;
};
