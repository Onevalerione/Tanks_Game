#include "Constants.h"


//Класс танка.
class Ttank {
public:
    int x,y;
    int sX, sY;
    Tdir dir;
    Ttank(int startX, int startY)
    { dir = Rup; sX = startX; sY = startY; SetToStart(); }
    void Show(mapHW &map);
    void Move(char w, char s, char a, char d, char fire);
    //Возвращение танка в точку спавна.
    void SetToStart() {x = sX; y = sY; }
    bool IsHoriz() {return (dir == Rright || dir == Rleft); }
    RECT GetRect() { RECT r = {x-1, y-1, x+1, y+1}; return r; }

};

//Класс пуль.
class Tpula {
public:
    int x,y;
    int speed;
    Tdir dir;
    bool use;
    Tpula() { use = 0; speed = 5; }
    void SetPula(int px, int py, Tdir pdir)
    {x = px; y =py; dir = pdir; use = 1; }
    void Move();
    void Show(mapHW &map) {if (!use) return; map[y][x] = '*'; }

};


//Класс препятствия.
class Tbrick {
public:
    RECT rct;
    bool use;
    Tmatter tp;

    Tbrick() {use = 0;tp = ttBrick; }
    void Show(mapHW &map);
    void SetPos(int px, int py) {RECT r ={px-1, py-1, px+1, py+1}; rct =r; use = 1; }
    RECT GetRect() { return rct; }

};

