#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "tile.hpp"

class Level {
    public:
        Level();
        void generate(int rows, int cols, int bomb_count);
        inline std::vector<std::vector<Tile>> getLevel() { return level; }
    private:
        std::vector<std::vector<Tile>> level;
};
