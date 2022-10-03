#include "../include/level.hpp"
#include "../include/tile.hpp"
#include "../include/defaults.hpp"
#include "SFML/Graphics.hpp"
#include <random>
#include <iostream>
#include <algorithm>
#include <vector>


Level::Level() {
    totalFlags = 0;
    correctFlags = 0;
    generate(ROWS, COLUMNS, NUM_MINES);
    if(!tileSheet.loadFromFile("assets/tiles.png")){
        std::cout << "Could not load \"tiles.png\"!" << std::endl;
    }

    sprite.setTexture(tileSheet);
    initIntRect();
}


void Level::generate(int rows, int cols, int bomb_count){
    int start = 0;
    int curCol = 0;
    int curRow = 0;
    int end = rows * cols;

    // 1D Vector for bombs
    std::vector<int> v(end);
    std::iota(v.begin(), v.end(), 0);

    // Random shuffle for bombs

    std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});

    // Initialize level
    std::vector<std::vector<Tile>> level(rows, std::vector<Tile> (cols, Tile()));

    for(int i = 0; i < bomb_count; i++){
        curRow = v.back();
        // Convert 1D pos to 2D
        if(curRow > rows-1){
            curCol = curRow / rows;
            curRow = curRow % rows;
            std::cout << "row: " << curRow+1 << " col: " << curCol+1 << std::endl;
        }
        level[curRow][curCol].addBomb();

        // Test out of bounds
        if(curRow < rows-1){
            level[curRow+1][curCol].addBombNear();
        }
        if(curRow-1 >= 0){
            level[curRow-1][curCol].addBombNear();
        }
        if(curCol < cols-1){
            level[curRow][curCol+1].addBombNear();
        }
        if(curCol-1 >= 0){
            level[curRow][curCol-1].addBombNear();
        }
        if(curRow < rows-1 and curCol < cols-1){
            level[curRow+1][curCol+1].addBombNear();
        }
        if(curRow < rows-1 and curCol-1 >=0){
            level[curRow+1][curCol-1].addBombNear();
        }
        if(curRow-1 >= 0 and curCol < cols-1){
            level[curRow-1][curCol+1].addBombNear();
        }
        if(curRow-1 >= 0 and curCol-1>=0){
            level[curRow-1][curCol-1].addBombNear();
        }
   
        v.pop_back();
    }

    lvl = level;
} 



void Level::draw(sf::RenderWindow &window) {
    sf::IntRect placeHolder;
    bool found;
    bool flagged;
    bool isBomb;
    int numBombs;

    
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            found = lvl[row][column].getIsFound();
            if(found){
                numBombs = lvl[row][column].getNumBombs();
                switch(numBombs){
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
                flagged = lvl[row][column].getIsFlagged();
                if(flagged) {
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

bool Level::checkWin(){
    if(correctFlags == totalFlags and correctFlags == NUM_MINES){
        return true;
    }
    std::cout << totalFlags << " total flags and " << correctFlags << " correct flags" << std::endl;
    return false;
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
