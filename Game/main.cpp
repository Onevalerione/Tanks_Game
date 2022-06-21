#include <ctime>
#include <windows.h>
#include "pula.cpp"
#include "tanks.cpp"
#include "brick.cpp"

using namespace std;


int main()
{
    system("mode con cols=80 lines=25"); //< Параметры консоли
    srand(time(0));
    CreateBattleField(); //< Генерация карты

    do
    {
        tank[0].Move('W','S','A','D', VK_SPACE);//< Клавишы для управление танком 1
        tank[1].Move(38,40,37,39,13);//< Клавишы для управление танком 2
        for (int i = 0; i < pulaCnt; pula[i++].Move());//< Движение пули

        scr.Clear();
        for (int i = 0; i < tankCnt; tank[i++].Show(scr.map));//< Отображение на экране
        for (int i = 0; i < brickCnt; brick[i++].Show(scr .map));//< Отображение на экране
        for (int i = 0; i < pulaCnt; pula[i++].Show(scr .map));//< Отображение на экране
        scr.Show();

        Sleep(100);
    }
    while (GetKeyState(VK_ESCAPE)  >= 0);
    return 0;
}




