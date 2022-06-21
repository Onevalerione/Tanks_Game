#include "Checks.cpp"



//Вывод танка на консоль (горизонтальная и вертикальная отрисовка гусениц, положение дула).
void Ttank::Show(mapHW &map)
{
    if (IsHoriz())
        for (int i = -1; i < 2; map[y-1][x+i] = map[y+1][x+i] = catter, i++);
    else
        for (int i = -1; i < 2; map[y+i][x-1] = map[y+i][x+1] = catter, i++);
    map[y][x] = tankC;
    POINT dt = dirInc[dir];
    map[y + dt.y][x + dt.x] = IsHoriz() ? duloH : duloV;
}


//Управление танком.
void Ttank::Move(char w, char s, char a, char d ,char fire)
{
    char wsad[4] = {w,s,a,d};
    for( int i = 0; i < 4; i++)
        if  (GetKeyState(wsad[i]) < 0)  dir = (Tdir)i;
    POINT pt = dirInc[dir];
    //Текущие значения танка.
    Ttank old = *this;
    x += pt.x;
    y += pt.y;
    //Взаимодействие танка с другими обЪектами.
    if (!IsCross(area, GetRect()) ||
        (CheckCrossAnyTank(GetRect(), this) != 0) ||
        (CheckCrossAnyBrick(GetRect()) != 0))
        *this = old;
    //Реализация стрельбы.
    if (GetKeyState(fire) < 0)
        GetFreePula().SetPula(x + pt.x*2, y + pt.y*2, dir);
}


