#include "SFML/Graphics.hpp"
#include "../include/tile.hpp"
#include "../include/level.hpp"
#include "../include/defaults.hpp"
#include <iostream>

Tile::Tile() {
    isBomb = false;
    found = false;
    flagged = false;
    bombsNear = 0; 
}

