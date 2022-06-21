#include "classes.cpp"
#include <iostream>

/**
 *  Устанавливает положение курсора на экране
 * brief установка положение курсора
 * @param x
 * @param y
 */

//Функция установки положения курсора консоли.
void SetCurPos(int x, int y)
{
    COORD coord;
    coord.X = x;//<x координата положения курсора консоли
    coord.Y = y;//<y координата положения курсора консоли
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//<установка положения курсора
}

/**
 * Структура для управления картой
 * @brief содержит функции для заполнения карты символом, установки в массив карты символ конца строки, отображения карты в консоли
 */
//Структура для управления картой.
struct Tmap {
    mapHW map;//<карта
    /**
     * Метод Clear()
     * Функция для заполнение карты символом
     */
    void Clear() {memset(map, field, sizeof(map)-1);}//<заполнение карты символом
    /**
     * Метод SetEnd()
     * Функция установки в массив карты символ конца строки
     *
     */
    void SetEnd() { map[height-1][width-1] = '\0'; }//<Установка в массив карты символ конца строки
    /**
     * Метод Show()
     * Функция отображния карты в косноли
     * @brief показывает карту в консоли
     *
     */
    void Show () { SetCurPos(0,0); SetEnd(); cout << map[0]; }//<Отображение карты в консоли
};


/**
 * Массивы данных для обЪектов
 */
Tmap scr;
const int tankCnt =  2;
Ttank tank[tankCnt] = { Ttank (1,11), Ttank(78, 11) };//<Координаты объекта танка
const int brickCnt =  300;
Tbrick brick[brickCnt];//< Массив препятствия
const int pulaCnt =  100;
Tpula pula[pulaCnt];//< Массив пули



/**
 * Отвечает за взаимодействие объектов танков между собой
 * @param a
 * @param b
 * @return (a.right >= b.left) && (a.left <= b.right)
          && (a.bottom >= b.top) && (a.top <= b.bottom);
 */
bool IsCross(RECT a, RECT b)
{
    return(a.right >= b.left) && (a.left <= b.right)
          && (a.bottom >= b.top) && (a.top <= b.bottom);
}


/**
 *
 * Отвечает за генерацию ландшафта
 */
//Генерация ландшафта.
void CreateBattleField()
{
    int pos = 0;
    for (int i = 5; i < width-5; i += 3)//< Проход по всей карте с шагом в клетку
        for (int j = 1; j < height-1; j += 3)
        {
            /**
             * Setpos()
             * @param i
             * @param j
             */
            brick[pos].SetPos(i, j);
            if (rand() % 5 == 0) brick[pos].tp = ttStone;//< Генерация камня
            if (rand() % 5 == 0) brick[pos].use = 0;//< Генерация пустоты
            pos++;//< Переход к следующму блоку
        }
}


/**
 * Функция отвечает за выбор свободной пули
 * @brief Поиск первого свободного элемента
 * Возвращение элемента
 * @return pula[0]
 * Возвращение первого элемента массива
 */
//Функция выбора свободной пули.
Tpula &GetFreePula()
{
    for (int i = 0; i < pulaCnt; i++)//< Поиск первого свободного элемента
        if (!pula[i].use) return pula[i];//< Возвращение элемента
    return pula[0];//< Возвращение первого элемента массива
}

