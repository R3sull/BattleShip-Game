#include <iostream>
#include <conio.h>
#include "windows.h"
using namespace std;

#include "functions.h"

int main()
{
    const int rows = 14;
    const int elements = 14;
    bool gametype = true;
    int matrix[rows][elements] = {};
    int startedGame[rows][elements] = {};
    int destroyer = 1, subMarine = 2, battleShip = 3, carrier = 4;
    mainScreen();
    secondScreen(gametype);
    if (gametype) {
        setupGame('x', matrix, 0, destroyer, subMarine, battleShip, carrier);
        CreateEnemy();
        PlayGame(startedGame);
    }
}