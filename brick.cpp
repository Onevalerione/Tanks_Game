#include "Checks.cpp"




//Отображение препятствий.
void Tbrick::Show(mapHW &map)
{
    if (!use) return;
    for (int i = rct.left; i <= rct.right; i++)
        for (int j = rct.top; j <= rct.bottom; j++)
            if (tp == ttBrick)
                map[j][i] = fbrick;
            else
                map[j][i] = fstone;
}

