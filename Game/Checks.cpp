#pragma once
#include "Functions.cpp"


//Столкновение танков между собой.
Ttank *CheckCrossAnyTank(RECT rct, Ttank *accept)//< Область для проверки
{
    for ( int i = 0; i < tankCnt; i++)
        if ((accept != tank+i) &&//< Если активно
            (IsCross(rct, tank[i].GetRect())) )//< Проверка пересечения прямоугольника объекта и танка
            return tank + i;//< Возвращение указателя на танк
    return 0;
}

//Столкновение танков с препятствиями.
Tbrick *CheckCrossAnyBrick(RECT rct)
{
    for (int i = 0; i < brickCnt; i++)
        if (brick[i].use &&//< Если активно
            IsCross(rct, brick[i].GetRect()) )//< Проверка пересечения объектов
            return brick + i;//< Возвращение указателя на объект
    return 0;
}

