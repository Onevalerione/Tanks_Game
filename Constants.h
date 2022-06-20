#include <windows.h>
#include <iostream>

using namespace std;

#define width 80
#define height 25

#define field ' '
#define fbrick 176
#define fstone 206

#define duloV 179
#define duloH 205
#define catter '#'
#define tankC 219

typedef char mapHW[height][width];


//Данные связанные с направленим движения танка.
enum Tdir {Rup = 0, Rdown, Rleft, Rright};
POINT dirInc[] = {{0,-1}, {0,1}, {-1,0}, {1,0}};


RECT area = {2,2, width-3,height-3 };


RECT areaPula = {0,0, width-1,height-1};


//Тип прептствия.
enum Tmatter {ttStone, ttBrick};


