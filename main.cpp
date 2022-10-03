#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "include/defaults.hpp"
#include "include/level.hpp"
#include <iostream>

int main(){
    int sprite_size = SCREEN_HEIGHT / COLUMNS;
    sf::RenderWindow window(sf::VideoMode(SCREEN_HEIGHT, SCREEN_WIDTH), "Minesweeper");

    Level level = Level();

    while(window.isOpen()) {

        sf::Event event;
        sf::Vector2<int> pos;

        while(window.pollEvent(event)) {
            switch (event.type){

                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    pos.x = event.mouseButton.x;
                    pos.y = event.mouseButton.y;
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        std::cout << "left pressed" << std::endl;
                        std::cout << "x: " << pos.x << " y: " << pos.y << std::endl;
                    }


                    break;
            }
        }
        window.clear();
        level.draw(window);
        window.display();
    }
}
