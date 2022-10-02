#pragma once

class Tile{
    public:
        inline Tile() { isBomb = false; found = false; flag = false; bombsNear = 0; }
        inline bool getIsBomb() { return isBomb; }
        inline bool getIsFound() { return found; }
        inline bool getIsFlagged() { return flag; }
        inline int getNumBombs() { return bombsNear; }
        inline void setFlag() { flag = true; }
        inline void addBombNear() { bombsNear++; }
        inline void addBomb() { isBomb = true; }
    private:
        bool isBomb;
        bool found;
        bool flag;
        int bombsNear;
};
