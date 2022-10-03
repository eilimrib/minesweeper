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

    if(!tileSheet.loadFromFile("assets/tiles.png")){
        std::cout << "Could not load \"tiles.png\"!" << std::endl;
    }

    sprite.setTexture(tileSheet); 
}


void Tile::setRect(sf::IntRect rect){
    sprite.setTextureRect(rect);
}


void Tile::setPos(int x, int y){
    sprite.setPosition(x, y);
}


void Tile::drawSprite(sf::RenderWindow &window){
    window.draw(sprite);
}