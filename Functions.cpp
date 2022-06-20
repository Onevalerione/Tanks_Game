#include "classes.cpp"
#include <iostream>



//Функция установки положения курсора консоли.
void SetCurPos(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


//Структура для управления картой.
struct Tmap {
    mapHW map;
    void Clear() {memset(map, field, sizeof(map)-1);}
    void SetEnd() { map[height-1][width-1] = '\0'; }
    void Show () { SetCurPos(0,0); SetEnd(); cout << map[0]; }
};

Tmap scr;
#define tankCnt 2
Ttank tank[tankCnt] = { Ttank (1,11), Ttank(78, 11) };
#define brickCnt 300
Tbrick brick[brickCnt];
#define pulaCnt 100
Tpula pula[pulaCnt];




//Перемещение танка.
bool IsCross(RECT a, RECT b)
{
    return(a.right >= b.left) && (a.left <= b.right)
          && (a.bottom >= b.top) && (a.top <= b.bottom);
}



//Генерация ландшафта.
void CreateBattleField()
{
    int pos = 0;
    for (int i = 5; i < width-5; i += 3)
        for (int j = 1; j < height-1; j += 3)
        {
            brick[pos].SetPos(i, j);
            if (rand() % 5 == 0) brick[pos].tp = ttStone;
            if (rand() % 5 == 0) brick[pos].use = 0;
            pos++;
        }
}



//Функция выбора свободной пули.
Tpula &GetFreePula()
{
    for (int i = 0; i < pulaCnt; i++)
        if (!pula[i].use) return pula[i];
    return pula[0];
}

