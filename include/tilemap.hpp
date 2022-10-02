#pragma once

#include "SFML/Graphics.hpp"
#include "level.hpp"


class Tilemap {
    public:
        Tilemap();
        void draw(sf::RenderWindow &window, Level level);

    private:
        void initIntRect();

        const int tileWidth;
        const int tileHeight;

        sf::Texture tileSheet;
        sf::Sprite tile;

        sf::IntRect hidden;
        sf::IntRect blank;
        sf::IntRect bomb;
        sf::IntRect flag;
        sf::IntRect one;
        sf::IntRect two;
        sf::IntRect three;
        sf::IntRect four;
};
