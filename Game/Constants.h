#include <windows.h>
#include <iostream>

using namespace std;


/// Ширина карты
const int width =  80;
/// Высота карты
const int height =  25;
/// Символ, заполняющий поле
const int field =  ' ';
/// Символ кирпичей
const int fbrick =  176;
/// Символ камня
const int fstone =  206;
/// Символ дула по горизонтали
const int duloH =  205;
/// Символ дула по вертикали
const int duloV =  179;
/// Символ для гусениц
const int catter =  '#';
/// Символ корпуса танка
const int tankC =  219;


///Тип данных для карты
typedef char mapHW[height][width];


/**
 * Данные связанные с направленим движения танка.
 * @brief тип данных, который ъранит направления движения танка, хранит изменения координат при движении
 */
//Данные связанные с направленим движения танка.
enum Tdir {Rup = 0, Rdown, Rleft, Rright};//<Хранит направление движения танка
POINT dirInc[] = {{0,-1}, {0,1}, {-1,0}, {1,0}};//<Хранит изменения координат при движении

/// Размер области
RECT area = {2,2, width-3,height-3 };

/// Область движения пули
RECT areaPula = {0,0, width-1,height-1};


/// Тип прептствия.
enum Tmatter {ttStone, ttBrick};


