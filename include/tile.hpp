#pragma once

class Tile{
    public:
        Tile();
        inline bool getIsBomb() { return isBomb; }
        inline bool getIsFound() { return found; }
        inline bool getIsFlagged() { return flagged; }
        inline int getNumBombs() { return bombsNear; }
        inline sf::Sprite getSprite() { return sprite; }
        
        inline void setFlag() { flagged = !flagged; }
        inline void addBombNear() { bombsNear++; }
        inline void addBomb() { isBomb = true; }
        void setRect(sf::IntRect rect);
        void setPos(int x, int y);
        void drawSprite(sf::RenderWindow &window);
    private:
        bool isBomb;
        bool found;
        bool flagged;
        int bombsNear;

        sf::Texture tileSheet;
        sf::Sprite sprite;
};
