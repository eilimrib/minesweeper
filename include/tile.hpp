#pragma once

class Tile{
    public:
        Tile();
        inline bool getIsBomb() { return isBomb; }
        inline bool getIsFound() { return found; }
        inline bool getIsFlagged() { return flagged; }
        inline int getNumBombs() { return bombsNear; }
        
        inline void setFlag() { flagged = !flagged; }
        inline void setFound() { if(!isBomb) { found = true; }}
        inline void addBombNear() { if(!isBomb){ bombsNear++;} }
        inline void addBomb() { isBomb = true; }
    private:
        bool isBomb;
        bool found;
        bool flagged;
        int bombsNear;
};
