#include "Constants.h"

/**
 * class Ttank
 * Содержит основные методы для танка
 */

//Класс танка.
class Ttank {
public:
    int x,y;//< Координаты положения танка
    int sX, sY;//< Координаты начального положения танка
    Tdir dir;//< Показывает направление танка
    Ttank(int startX, int startY)//< Конструктор, передаем начальное положение танка
    { dir = Rup; sX = startX; sY = startY; SetToStart(); }
    /**
     * Метод Show()
     * отображает танк на карте
     * @param map
     */
    void Show(mapHW &map);
    /**
     * Метод Move()
     * Отвечает за движение танка
     * @param w
     * @param s
     * @param a
     * @param d
     * @param fire
     */
    void Move(char w, char s, char a, char d, char fire);
    //Возвращение танка в точку спавна.
    /**
     * Метод SetToStart()
     * Возвращение танка в точку спавна
     */
    void SetToStart() {x = sX; y = sY; }
    /**
     * Проверка, что танк смотрит по горизонтали
     * @return (dir == Rright || dir == Rleft)
     *
     */
    bool IsHoriz() {return (dir == Rright || dir == Rleft); }
    /**
     * @return r
     * Возвращает область занимаемую танком
     */
    RECT GetRect() { RECT r = {x-1, y-1, x+1, y+1}; return r; }

};
/**
 * Класс пуль
 * Содержит основные методы для пули
 */
//Класс пуль.
class Tpula {
public:

    int x,y;//< Координаты пули
    int speed;//< Скорость пули в клетках
    Tdir dir;//< Направление пули
    bool use;//< Использование пули
    /**
     * Задает параметры пули по умлочанию
     */
    Tpula() { use = 0; speed = 5; }
    /**
     * SetPula()
     * Создание пули в указанной точке
     * @param px
     * @param py
     * @param pdir
     */
    void SetPula(int px, int py, Tdir pdir)
    {x = px; y =py; dir = pdir; use = 1; }
    /**
     * Перемещение пули
     */
    void Move();
    /**
     *  Отображение пули, если она активна
     * @param map
     */
    void Show(mapHW &map) {if (!use) return; map[y][x] = '*'; }

};

/**
 * Класс препятствий
 * Содержит основные методы для препятствий
 *
 */
//Класс препятствия.
class Tbrick {
public:
    RECT rct; //< Область, которую занимает препятствие
    bool use; //< Включение нужных объектов
    Tmatter tp; //< Тип препятствия

    /**
     * Задает препятствие по умлочанию - кирпич
     */
    Tbrick() {use = 0;tp = ttBrick; }
    /**
     * Отображение прептствия на карте
     * @param map
     */
    void Show(mapHW &map);
    /**
     * Помещение препятствия в нужную точку
     * @param px
     * @param py
     */
    void SetPos(int px, int py) {RECT r ={px-1, py-1, px+1, py+1}; rct =r; use = 1; }
    /**
     * Изображение прямоугольника объекта
     * @return rct
     *
     */
    RECT GetRect() { return rct; }

};

