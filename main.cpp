#include <SFML/Graphics.hpp>
#include "include/defaults.hpp"
#include "include/tilemap.hpp"
#include "include/level.hpp"

int main(){
    int sprite_size = SCREEN_HEIGHT / COLUMNS;
    sf::RenderWindow window(sf::VideoMode(SCREEN_HEIGHT, SCREEN_WIDTH), "Minesweeper");

    Tilemap map = Tilemap();
    Level lvl = Level();

    while(window.isOpen()) {

        sf::Event event;

        while(window.pollEvent(event)) {
            switch (event.type){

                case sf::Event::Closed:
                    window.close();
                    break;
            }

        }

        map.draw(window, lvl);
    }
}
