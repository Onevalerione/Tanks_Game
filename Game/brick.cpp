#include "Checks.cpp"




//Отображение препятствий.
void Tbrick::Show(mapHW &map)
{
    if (!use) return;//< Если не исползуется, то не показываем
    for (int i = rct.left; i <= rct.right; i++)//< Отрисовка препятствий
        for (int j = rct.top; j <= rct.bottom; j++)
            if (tp == ttBrick)
                map[j][i] = fbrick;//< Отрисовка кирпичей
            else
                map[j][i] = fstone;//< Отрисовка камней
}

