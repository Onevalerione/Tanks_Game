#pragma once
#include "Functions.cpp"


//Столкновение танков между собой.
Ttank *CheckCrossAnyTank(RECT rct, Ttank *accept)
{
    for ( int i = 0; i < tankCnt; i++)
        if ((accept != tank+i) &&
            (IsCross(rct, tank[i].GetRect())) )
            return tank + i;
    return 0;
}

//Столкновение танков с препятствиями.
Tbrick *CheckCrossAnyBrick(RECT rct)
{
    for (int i = 0; i < brickCnt; i++)
        if (brick[i].use &&
            IsCross(rct, brick[i].GetRect()) )
            return brick + i;
    return 0;
}

