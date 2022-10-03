#pragma once

class Tile{
    public:
        Tile();
        inline bool getIsBomb() { return isBomb; }
        inline bool getIsFound() { return found; }
        inline bool getIsFlagged() { return flagged; }
        inline int getNumBombs() { return bombsNear; }
        
        inline void setFlag() { flagged = !flagged; }
        inline void setFound() { found = true; }
        inline void addBombNear() { if(!isBomb){ bombsNear++;} }
        inline void addBomb() { isBomb = true; bombsNear = 0;}
    private:
        bool isBomb;
        bool found;
        bool flagged;
        int bombsNear;
};
