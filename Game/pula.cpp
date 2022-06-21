#include "Checks.cpp"




//Движение пули.
void Tpula::Move()
{
    if (!use) return;//< Не использование пули
    for (int i = 1; i < speed; i++)//< Проверка пути пули
    {
        x += dirInc[dir].x;//< Перемещение пули по координате x
        y += dirInc[dir].y;//< Перемещение пули по координате y
        RECT rct = {x,y,x,y};
        if (!IsCross(rct, areaPula)) use = 0;//< Передача области функции

        Tbrick *brick = CheckCrossAnyBrick(rct);//< Проверка на столкновение с препятсвием
        if (brick) use = 0, brick->use = (brick->tp == ttStone);//< Удаляем пулю или препятствие

        Ttank * tank = CheckCrossAnyTank(rct, 0); //< Взаимодействие с танком
        if (tank) use = 0, tank->SetToStart();//< Если попали, возвращаем танк на спавн

        if (!use) return;//< Выход из функции
    }
}
