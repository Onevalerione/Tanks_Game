#include <windows.h>
#include <iostream>

using namespace std;



const int width =  80;
const int height =  25;
const int field =  ' ';
const int fbrick =  176;
const int fstone =  206;
const int duloH =  205;
const int duloV =  179;
const int catter =  '#';
const int tankC =  219;



typedef char mapHW[height][width];//<Тип данных для карты



//Данные связанные с направленим движения танка.
enum Tdir {Rup = 0, Rdown, Rleft, Rright};//<Хранит направление движения танка
POINT dirInc[] = {{0,-1}, {0,1}, {-1,0}, {1,0}};//<Хранит изменения координат при движении


RECT area = {2,2, width-3,height-3 };//< Размер области


RECT areaPula = {0,0, width-1,height-1};//< Область движения пули


//Тип прептствия.
enum Tmatter {ttStone, ttBrick};


