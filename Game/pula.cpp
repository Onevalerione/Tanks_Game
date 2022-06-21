#include "Checks.cpp"




//Движение пули.
void Tpula::Move()
{
    if (!use) return;
    for (int i = 1; i < speed; i++)
    {
        x += dirInc[dir].x;
        y += dirInc[dir].y;
        RECT rct = {x,y,x,y};
        if (!IsCross(rct, areaPula)) use = 0;

        Tbrick *brick = CheckCrossAnyBrick(rct);
        if (brick) use = 0, brick->use = (brick->tp == ttStone);

        Ttank * tank = CheckCrossAnyTank(rct, 0);
        if (tank) use = 0, tank->SetToStart();

        if (!use) return;
    }
}
