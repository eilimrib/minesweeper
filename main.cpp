#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "include/defaults.hpp"
#include "include/level.hpp"
#include "include/tile.hpp"
#include <iostream>

int main(){
    int sprite_size = SCREEN_HEIGHT / COLUMNS;
    sf::RenderWindow window(sf::VideoMode(SCREEN_HEIGHT, SCREEN_WIDTH), "Minesweeper");

    Level level = Level();
    std::vector<std::vector<Tile>> lvl = level.getLevel();

    level.draw(window);
    window.display();
    while(window.isOpen()) {

        sf::Event event;
        sf::Vector2<int> pos;

        while(window.pollEvent(event)) {
            switch (event.type){

                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonReleased:
                    pos.x = (event.mouseButton.x - event.mouseButton.x % TILE_WIDTH)/ TILE_WIDTH;
                    pos.y = (event.mouseButton.y - event.mouseButton.y % TILE_HEIGHT)/ TILE_HEIGHT;
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        std::cout << "left pressed" << std::endl;
                        std::cout << "x: " << pos.x << " y: " << pos.y << std::endl;

                        if(lvl[pos.x][pos.y].getIsBomb()){
                            std::cout << "You died!!" << std::endl;
                            window.close();
                        } else {
                            if(!lvl[pos.x][pos.y].getIsFound()){
                                std::cout << lvl[pos.x][pos.y].getIsFound() << ": nothing here!!" << std::endl;
                                std::cout << lvl[pos.x][pos.y].getNumBombs() << " bombs near!" << std::endl;
                                lvl[pos.x][pos.y].setFound();
                                if(pos.x < ROWS-1){
                                    lvl[pos.x+1][pos.y].setFound();
                                }
                                if(pos.x-1 >= 0){
                                    lvl[pos.x-1][pos.y].setFound();
                                }
                                if(pos.y < COLUMNS-1){
                                    lvl[pos.x][pos.y+1].setFound();
                                }
                                if(pos.y-1 >=0){
                                    lvl[pos.x][pos.y-1].setFound();
                                }
                                if(pos.x < ROWS-1 and pos.y < COLUMNS-1){
                                    lvl[pos.x+1][pos.y+1].setFound();
                                }
                                if(pos.x < ROWS-1 and pos.y-1 >= 0){
                                    lvl[pos.x+1][pos.y-1].setFound();
                                }
                                if(pos.x-1 >= 0 and pos.y < COLUMNS-1){
                                    lvl[pos.x-1][pos.y+1].setFound();
                                }
                                if(pos.x-1 >=0 and pos.y-1 >= 0){
                                    lvl[pos.x-1][pos.y-1].setFound();
                                }
                            } else{
                                std::cout << lvl[pos.x][pos.y].getIsFound() << ": already found!!" << std::endl;
                            }
                        }
                    }
                    window.clear();
                    level.draw(window);
                    window.display();
                    break;
            }
        }
    }
}
