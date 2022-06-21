#include "Constants.h"


//Класс танка.
class Ttank {
public:
    int x,y;//< Координаты положения танка
    int sX, sY;//< Координаты начального положения танка
    Tdir dir;//< Показывает направление танка
    Ttank(int startX, int startY)//< Конструктор, передаем начальное положение танка
    { dir = Rup; sX = startX; sY = startY; SetToStart(); }
    void Show(mapHW &map);//< Отображение танка
    void Move(char w, char s, char a, char d, char fire);//< Движение танка
    //Возвращение танка в точку спавна.
    void SetToStart() {x = sX; y = sY; }//< Возвращение танка в точку спавна
    bool IsHoriz() {return (dir == Rright || dir == Rleft); }//< Проверка, что танк смотрит по горизонтали
    RECT GetRect() { RECT r = {x-1, y-1, x+1, y+1}; return r; }//< Возвращение области, занимаемой танком

};

//Класс пуль.
class Tpula {
public:
    int x,y;//< Координаты пули
    int speed;//< Скорость пули в клетках
    Tdir dir;//< Направление пули
    bool use;//< Использование пули
    Tpula() { use = 0; speed = 5; }//< Параметры пули по умлочанию
    void SetPula(int px, int py, Tdir pdir)//< Создание пули в указанной точке
    {x = px; y =py; dir = pdir; use = 1; }
    void Move();//< Перемещение пули
    void Show(mapHW &map) {if (!use) return; map[y][x] = '*'; }//< Отображение пули, если она активна

};


//Класс препятствия.
class Tbrick {
public:
    RECT rct; //< Область, которую занимает препятствие
    bool use; //< Включение нужных объектов
    Tmatter tp; //< Тип препятствия

    Tbrick() {use = 0;tp = ttBrick; } //< Препятствие по умлочанию кирпич
    void Show(mapHW &map); //< Отображение прептствия на карте
    void SetPos(int px, int py) {RECT r ={px-1, py-1, px+1, py+1}; rct =r; use = 1; }//< Помещение препятствия в нужную точку
    RECT GetRect() { return rct; }//< Изображение прямоугольника объекта

};

