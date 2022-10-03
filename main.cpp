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

    while(window.isOpen()) {

        sf::Event event;
        sf::Vector2<int> pos;

        while(window.pollEvent(event)) {
            switch (event.type){

                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonReleased:
                    pos.x = (event.mouseButton.x - event.mouseButton.x % TILE_WIDTH)/ COLUMNS;
                    pos.y = (event.mouseButton.y - event.mouseButton.y % TILE_HEIGHT)/ ROWS;
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        std::cout << "left pressed" << std::endl;
                        std::cout << "x: " << pos.x << " y: " << pos.y << std::endl;

                        if(lvl[pos.x][pos.y].getIsBomb()){
                            std::cout << "Sprite has bomb!!" << std::endl;
                        }
                    }
                    break;
            }
        }

        window.clear();
        level.draw(window);
        window.display();
    }
}
