#include <ctime>
#include <windows.h>
#include "pula.cpp"
#include "tanks.cpp"
#include "brick.cpp"

using namespace std;


int main()
{
    system("mode con cols=80 lines=25");
    srand(time(0));
    CreateBattleField();

    do
    {
        tank[0].Move('W','S','A','D', VK_SPACE);
        tank[1].Move(38,40,37,39,13);
        for (int i = 0; i < pulaCnt; pula[i++].Move());

        scr.Clear();
        for (int i = 0; i < tankCnt; tank[i++].Show(scr.map));
        for (int i = 0; i < brickCnt; brick[i++].Show(scr .map));
        for (int i = 0; i < pulaCnt; pula[i++].Show(scr .map));
        scr.Show();

        Sleep(100);
    }
    while (GetKeyState(VK_ESCAPE)  >= 0);
    return 0;
}




