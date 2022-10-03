#include "../include/level.hpp"
#include "../include/tile.hpp"
#include "../include/defaults.hpp"
#include "SFML/Graphics.hpp"
#include <random>
#include <iostream>


Level::Level() {
    generate(ROWS, COLUMNS, NUM_MINES);
    if(!tileSheet.loadFromFile("assets/tiles.png")){
        std::cout << "Could not load \"tiles.png\"!" << std::endl;
    }

    sprite.setTexture(tileSheet);
    initIntRect();
}


void Level::generate(int rows, int cols, int bomb_count){
    int start, num, curRow = 0;
    int end = rows * cols;

    // 1D Vector for bombs
    std::vector<int> v(end);
    std::iota(v.begin(), v.end(), start);

    // Random shuffle for bombs
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(v), std::end(v), rng);

    // Initialize level
    std::vector<std::vector<Tile>> lvl(rows, std::vector<Tile> (cols, Tile()));

    for(int i = bomb_count; i >= 0; i--){
        num = v.back();

        // Convert 1D pos to 2D
        while(num > rows){ 
            num = num % cols;
            curRow++;
        }
        lvl[curRow][num].addBomb();

        // Test out of bounds
        if(curRow < rows){
            lvl[curRow+1][num].addBombNear();
        }
        if(curRow-1 >= 0){
            lvl[curRow-1][num].addBombNear();
        }
        if(num < cols){
            lvl[curRow][num+1].addBombNear();
        }
        if(num-1 >= 0){
            lvl[curRow][num-1].addBombNear();
        }
        if(curRow < rows and num < cols){
            lvl[curRow+1][num+1].addBombNear();
        }
        if(curRow < rows and num-1 >=0){
            lvl[curRow+1][num-1].addBombNear();
        }
        if(curRow-1 >= 0 and num < cols){
            lvl[curRow-1][num+1].addBombNear();
        }
        if(curRow-1 >= 0 and num-1>=0){
            lvl[curRow-1][num-1].addBombNear();
        }
   
        v.pop_back();
    }

    level = lvl;
} 



void Level::draw(sf::RenderWindow &window) {
    const int mapRows = ROWS;
    const int mapColumns = COLUMNS;
    sf::IntRect placeHolder;
    
   	for (int row = 0; row < mapRows; row++) {
        for (int column = 0; column < mapColumns; column++) {
            if(level[row][column].getIsFound()){
                switch(level[row][column].getNumBombs()){
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
                } else {
                    if(level[row][column].getIsFlagged()) {
                        placeHolder = flag;
                    } else {
                        placeHolder = hidden;
                }
            }

            sprite.setTextureRect(placeHolder);
            sprite.setPosition((row * TILE_WIDTH), (column * TILE_HEIGHT));
            window.draw(sprite);
        }
    }
}

void Level::initIntRect(){
    hidden.left = 0;
    hidden.top = 0;
    hidden.width = TILE_WIDTH;
    hidden.height = TILE_HEIGHT;

    blank.left = 30;
    blank.top = 0;
    blank.width = TILE_WIDTH;
    blank.height = TILE_HEIGHT;

    bomb.left = 0;
    bomb.top = 30;
    bomb.width = TILE_WIDTH;
    bomb.height = TILE_HEIGHT;

    flag.left = 30;
    flag.top = 30;
    flag.width = TILE_WIDTH;
    flag.height = TILE_HEIGHT;

    one.left = 60;
    one.top = 0;
    one.width = TILE_WIDTH;
    one.height = TILE_HEIGHT;

    two.left = 90;
    two.top = 0;
    two.width = TILE_WIDTH;
    two.height = TILE_HEIGHT;

    three.left = 60;
    three.top = 30;
    three.width = TILE_WIDTH;
    three.height = TILE_HEIGHT;

    four.left = 90;
    four.top = 30;
    four.width = TILE_WIDTH;
    four.height = TILE_HEIGHT;    
}
