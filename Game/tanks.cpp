#include "Checks.cpp"



//Вывод танка на консоль (горизонтальная и вертикальная отрисовка гусениц, положение дула).
void Ttank::Show(mapHW &map)//< На вход получаем ссылку на карту
{
    if (IsHoriz())
        for (int i = -1; i < 2; map[y-1][x+i] = map[y+1][x+i] = catter, i++);//< Отрисовка гусениц танка в горизонтально
    else
        for (int i = -1; i < 2; map[y+i][x-1] = map[y+i][x+1] = catter, i++);//< Отрисовка гусениц танка вертикально
    map[y][x] = tankC;//< Отрисовка корпуса танка
    POINT dt = dirInc[dir];//< Выбор смещения по направлению танка
    map[y + dt.y][x + dt.x] = IsHoriz() ? duloH : duloV;//< Выбор положения дула танка
}


//Управление танком.
void Ttank::Move(char w, char s, char a, char d ,char fire)//<  Управляющие символы для танка
{
    char wsad[4] = {w,s,a,d};
    for( int i = 0; i < 4; i++)//< Обработка кнопок
        if  (GetKeyState(wsad[i]) < 0)  dir = (Tdir)i;//< Если  кнопка нажата задаем направление танка
    POINT pt = dirInc[dir];
    //Текущие значения танка.
    Ttank old = *this;//<  Указатель на текущий объект
    x += pt.x;//< Перемещение объекта по координате x
    y += pt.y;//< Перемещение объекта по координате y
    //Взаимодействие танка с другими обЪектами.
    if (!IsCross(area, GetRect()) ||//< Проверка выхода танка за экран
        (CheckCrossAnyTank(GetRect(), this) != 0) ||//< Столкновение с другим танком
        (CheckCrossAnyBrick(GetRect()) != 0)) //< Столкновение с препятствием
        *this = old;//< Возвращение предыдущего значения объекта
    //Реализация стрельбы.
    if (GetKeyState(fire) < 0)//< Нажатие клавишы
        GetFreePula().SetPula(x + pt.x*2, y + pt.y*2, dir);//< Получение свободной пули в массиве
}


