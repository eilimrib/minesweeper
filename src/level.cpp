#include "../include/level.hpp"
#include "../include/tile.hpp"
#include "../include/defaults.hpp"
#include "SFML/Graphics.hpp"
#include <random>

Level::Level() {
    generate(ROWS, COLUMNS, NUM_MINES);
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

        while(num > rows){ 
            num = num % cols;
            curRow++;
        }
        lvl[curRow][num].addBomb();
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
        
        v.pop_back();
    }

    level = lvl;
} 