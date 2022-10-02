#include <iostream>
#include "SFML/Graphics.hpp"
#include "../include/tilemap.hpp"
#include "../include/level.hpp"
#include "../include/defaults.hpp"

Tilemap::Tilemap() : tileWidth(30), tileHeight(30) {
    if(!tileSheet.loadFromFile("assets/tiles.png")){
        std::cout << "Could not load \"tiles.png\"!" << std::endl;
    }

    tile.setTexture(tileSheet); 
    initIntRect();
}


void Tilemap::draw(sf::RenderWindow &window, Level level) {
    const int mapRows = ROWS;
    const int mapColumns = COLUMNS;
    std::vector<std::vector<Tile>> lvl = level.getLevel();

    sf::IntRect placeHolder;
   	for (int row = 0; row < mapRows; row++) {
		for (int column = 0; column < mapColumns; column++) {
            if(lvl[row][column].getIsFound()){
                if(lvl[row][column].getIsFlagged()){
                    placeHolder = flag;
                }else {
                    switch(lvl[row][column].getNumBombs()){
                        case 0:
                            placeHolder = blank;
                            break;
                        case 1:
                            placeHolder = one;
                            break;
                        case 2:
                            placeHolder = two;
                            break;
                        case 3:
                            placeHolder = three;
                            break;
                        case 4:
                            placeHolder = four;
                    }
                }
            } else {
                placeHolder = hidden;
            }
            
			tile.setTextureRect(placeHolder);
			tile.setPosition((row * tileWidth), (column * tileHeight));
			window.draw(tile);
        }
    }
}


void Tilemap::initIntRect(){
	hidden.left = 0;
	hidden.top = 0;
	hidden.width = tileWidth;
	hidden.height = tileHeight;

	blank.left = 30;
	blank.top = 0;
	blank.width = tileWidth;
	blank.height = tileHeight;

	bomb.left = 0;
	bomb.top = 30;
	bomb.width = tileWidth;
	bomb.height = tileHeight;

	flag.left = 30;
	flag.top = 30;
	flag.width = tileWidth;
	flag.height = tileHeight;

    one.left = 60;
    one.top = 0;
    one.width = tileWidth;
    one.height = tileHeight;

    two.left = 90;
    two.top = 0;
    two.width = tileWidth;
    two.height = tileHeight;

    three.left = 60;
    three.top = 30;
    three.width = tileWidth;
    three.height = tileHeight;

    four.left = 90;
    four.top = 30;
    four.width = tileWidth;
    four.height = tileHeight;    
}
