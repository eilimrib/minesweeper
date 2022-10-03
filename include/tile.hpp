#pragma once

class Tile{
    public:
        Tile();
        inline bool getIsBomb() { return isBomb; }
        inline bool getIsFound() { return found; }
        inline bool getIsFlagged() { return flagged; }
        inline int getNumBombs() { return bombsNear; }
        
        inline void setFlag() { flagged = !flagged; }
        inline void addBombNear() { bombsNear++; }
        inline void addBomb() { isBomb = true; }
        inline void setCoords(int x, int y) { coords.x = x; coords.y = y; }
    private:
        bool isBomb;
        bool found;
        bool flagged;
        int bombsNear;

        sf::Vector2<int> coords;
};
