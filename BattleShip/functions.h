#pragma once
int flagint = 0;
int choice = 0, lastRow = 7, lastColumn = 7;
bool active1 = true, active2 = false;
int gameTable[14][14] = {};
int enemyTable[14][14] = {};

void asciiPrint() {
    system("cls");
    cout << "\n\n\t\t\tXXXXX    XXXX   XXXXXX  XXXXXX  XX      XXXXXX    XXXXX  XX  XX  XX  XXXXX\n";
    cout << "\t\t\tXX  XX  XX  XX    XX      XX    XX      XX       XX      XX  XX  XX  XX  XX\n";
    cout << "\t\t\tXX  XX  XX  XX    XX      XX    XX      XX       XX      XX  XX  XX  XX  XX\n";
    cout << "\t\t\tXXXXX   XX  XX    XX      XX    XX      XXXX      XXXX   XXXXXX  XX  XXXXX\n";
    cout << "\t\t\tXX  XX  XXXXXX    XX      XX    XX      XX           XX  XX  XX  XX  XX\n";
    cout << "\t\t\tXX  XX  XX  XX    XX      XX    XX      XX           XX  XX  XX  XX  XX\n";
    cout << "\t\t\tXXXXX   XX  XX    XX      XX    XXXXXX  XXXXXX   XXXXX   XX  XX  XX  XX\n";
    cout << "\n\n\n\t\t\t\t\t     BattleShip Game\n";
}

int mainScreen() {
    int load = 0;
    while (load < 101) {
        cout << "\n\n\n\t\t\t\t\tThe BattleShip Game Is Starting!\n\t\t\t\t\t\tLOADING... " << load << "%\n\n\n";
        load += rand() % 20;
        cout << "\n\n\t\t\tXXXXX    XXXX   XXXXXX  XXXXXX  XX      XXXXXX    XXXXX  XX  XX  XX  XXXXX\n";
        cout << "\t\t\tXX  XX  XX  XX    XX      XX    XX      XX       XX      XX  XX  XX  XX  XX\n";
        cout << "\t\t\tXX  XX  XX  XX    XX      XX    XX      XX       XX      XX  XX  XX  XX  XX\n";
        cout << "\t\t\tXXXXX   XX  XX    XX      XX    XX      XXXX      XXXX   XXXXXX  XX  XXXXX\n";
        cout << "\t\t\tXX  XX  XXXXXX    XX      XX    XX      XX           XX  XX  XX  XX  XX\n";
        cout << "\t\t\tXX  XX  XX  XX    XX      XX    XX      XX           XX  XX  XX  XX  XX\n";
        cout << "\t\t\tXXXXX   XX  XX    XX      XX    XXXXXX  XXXXXX   XXXXX   XX  XX  XX  XX\n";
        cout << "\n\n\n\t\t\t\t\t     BattleShip Game\n";
        Sleep(150);
        system("cls");
    }
    int selected = 0;
    bool active = true;
    asciiPrint();
    cout << "\t\t\t>> Play\n";
    cout << "\t\t\t   Exit\n";
    char c;
    while (active) {
        switch ((c = _getch())) {
        case 72:      
            if (selected != 0)
                selected--;
            break;
        case 80:    
            if (selected == 0)
                selected++;
            break;
        case '\r':
            if (selected == 0) {
                active = false;
            }
            else {
                exit(0);
            }
            break;
        default: break;
        }
        if (active) {
            if (selected == 0) {
                asciiPrint();
                cout << "\t\t\t>> Play\n";
                cout << "\t\t\t   Exit\n";
            }
            else {
                asciiPrint();
                cout << "\t\t\t   Play\n";
                cout << "\t\t\t>> Exit\n";
            }
        }
    }
    return 0;
}

int secondScreen(bool &gametype) {
    int selected = 0;
    bool active = true;
    asciiPrint();
    cout << "\t\t\t>> Random\n";
    cout << "\t\t\t   Manually\n";
    char c;
    while (active) {
        switch ((c = _getch())) {
        case 72:
            if (selected != 0)
                selected--;
            break;
        case 80:
            if (selected == 0)
                selected++;
            break;
        case '\r':
            if (selected == 0) {
                active = false;
            }
            else {
                active = false;
            }
            break;
        default: break;
        }
        if (active) {
            if (selected == 0) {
                asciiPrint();
                cout << "\t\t\t>> Random\n";
                cout << "\t\t\t   Manually\n";
                gametype = false;
            }
            else {
                asciiPrint();
                cout << "\t\t\t   Random\n";
                cout << "\t\t\t>> Manually\n";
            }
        }
    }
    return 0;
}

int setupGame(char type, int matrix[14][14], int len = 1, int destroyer = 0, int subMarine = 0, int battleShip = 0, int carrier = 0) {
    system("cls");
    cout << "(row)X: " << lastRow << "\n(col)Y: " << lastColumn << "\nRotation: " << type << " Axis" << endl;
    cout << "Player Board" << endl;
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14; j++) {
            if (i != lastRow && j != lastColumn)
                matrix[i][j] = 0;
        }
    }
    int size = 15;
    int tempX = 0;
    int tempY = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {    
            if (i == 0 || j == 0 || i == size - 1 || j == size - 1) cout << "* ";
            else if (matrix[i][j]) {
                cout << "$" << " ";
                if (type == 'x') {
                    if (len > tempX + 1) {
                        tempX++;
                        matrix[i + 1][j] = 1;
                    }
                }
                else {
                    if (len > tempY + 1) {
                        tempY++;
                        matrix[i][j + 1] = 1;
                    }
                }
            }
            else if (gameTable[i][j]) cout << "$" << " ";
            else cout << "  ";

        }
        cout << endl;
    }
    if (choice != 5) {
        cout << "Remaining WarShips : " << endl;
        if (destroyer && choice == 0) cout << ">> Destroyer(" << destroyer << ") ~ 4" << endl;
        else cout << "   Destroyer(" << destroyer << ") ~ 4" << endl;

        if (subMarine && choice == 1) cout << ">> SubMarine(" << subMarine << ") ~ 3" << endl;
        else cout << "   SubMarine(" << subMarine << ") ~ 3" << endl;
        if (battleShip && choice == 2) cout << ">> BattleShip(" << battleShip << ") ~ 2" << endl;
        else cout << "   BattleShip(" << battleShip << ") ~ 2" << endl;
        if (carrier && choice == 3) cout << ">> Carrier(" << carrier << ") ~ 1" << endl;
        else cout << "   Carrier(" << carrier << ") ~ 1" << endl;
    }
    else {
        cout << ">> Play" << endl;
    }
    char c;
    while (active1) {
        switch ((c = _getch())) {
        case 72:
            if (choice > flagint && choice != 5) {
                choice--;
            }

            setupGame(type, matrix, 0, destroyer, subMarine, battleShip, carrier);
            break;
        case 80:
            if (choice < 3 && choice != 5)
                choice++;
            setupGame(type, matrix, 0, destroyer, subMarine, battleShip, carrier);
            break;
        case '\r':
            if (choice == 5) {
                active1 = false;
                active2 = false;
            }
            else {
                active1 = false;
                active2 = true;
                //matrix[lastRow][lastColumn] = 1;
                setupGame(type, matrix, 0, destroyer, subMarine, battleShip, carrier);
            }
            break;
        default: break;
        }
    }
    while (active2) {
        switch ((c = _getch())) {
        case 72: // UP
            if (lastRow - 1 > 0 && gameTable[lastRow - 2][lastColumn] != 1 && gameTable[lastRow - 2][lastColumn + 1] != 1 && gameTable[lastRow - 2][lastColumn - 1] != 1) {
                if (choice == 0 && destroyer != 0) {
                    if (type == 'x') {
                        lastRow--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow + 4][lastColumn] = 0;
                        setupGame(type, matrix, 4, destroyer, subMarine, battleShip, carrier);
                    }
                    else {
                        lastRow--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow + 1][lastColumn] = 0;
                        matrix[lastRow + 2][lastColumn] = 0;
                        matrix[lastRow + 3][lastColumn] = 0;
                        matrix[lastRow + 4][lastColumn] = 0;
                        setupGame(type, matrix, 4, destroyer, subMarine, battleShip, carrier);
                    }
                }
                else if (choice == 1 && subMarine != 0) {
                    if (type == 'x') {
                        lastRow--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow + 3][lastColumn] = 0;
                        setupGame(type, matrix, 3, destroyer, subMarine, battleShip, carrier);
                    }
                    else {
                        lastRow--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow + 1][lastColumn] = 0;
                        matrix[lastRow + 2][lastColumn] = 0;
                        matrix[lastRow + 3][lastColumn] = 0;
                        setupGame(type, matrix, 3, destroyer, subMarine, battleShip, carrier);
                    }
                }
                else if (choice == 2 && battleShip != 0) {
                    if (type == 'x') {
                        lastRow--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow + 2][lastColumn] = 0;
                        setupGame(type, matrix, 2, destroyer, subMarine, battleShip, carrier);
                    }
                    else {
                        lastRow--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow + 1][lastColumn] = 0;
                        matrix[lastRow + 2][lastColumn] = 0;
                        setupGame(type, matrix, 2, destroyer, subMarine, battleShip, carrier);
                    }
                }
                else if (choice == 3 && carrier != 0) {
                    lastRow--;
                    matrix[lastRow][lastColumn] = 1;
                    matrix[lastRow + 1][lastColumn] = 0;
                    setupGame(type, matrix, 1, destroyer, subMarine, battleShip, carrier);
                }
                else {
                    active1 = true;
                    active2 = false;
                    setupGame(type, matrix, 0, destroyer, subMarine, battleShip, carrier);
                }
            }
            break;
        case 80: // Down
            if (choice == 0 && destroyer != 0) {
                if (type == 'x') {
                    if (lastRow + 1 > 0 && lastRow + 1 < 11 && gameTable[lastRow + 5][lastColumn] != 1 && gameTable[lastRow + 5][lastColumn + 1] != 1 && gameTable[lastRow + 5][lastColumn - 1] != 1) {
                        lastRow++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow - 1][lastColumn] = 0;
                        setupGame(type, matrix, 4, destroyer, subMarine, battleShip, carrier);
                    }
                }
                else {
                    if (lastRow + 1 > 0 && lastRow + 1 < 14 && gameTable[lastRow + 2][lastColumn] != 1 && gameTable[lastRow + 2][lastColumn + 1] != 1 && gameTable[lastRow + 2][lastColumn - 1] != 1) {
                        lastRow++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow - 1][lastColumn] = 0;
                        matrix[lastRow + 1][lastColumn] = 0;
                        matrix[lastRow + 2][lastColumn] = 0;
                        setupGame(type, matrix, 4, destroyer, subMarine, battleShip, carrier);
                    }
                }
            }
            else if (choice == 1 && subMarine != 0) {
                if (type == 'x') {
                    if (lastRow + 1 > 0 && lastRow + 1 < 12 && gameTable[lastRow + 4][lastColumn] != 1 && gameTable[lastRow + 4][lastColumn + 1] != 1 && gameTable[lastRow + 4][lastColumn - 1] != 1) {
                        lastRow++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow - 1][lastColumn] = 0;
                        setupGame(type, matrix, 3, destroyer, subMarine, battleShip, carrier);
                    }
                }
                else {
                    if (lastRow + 1 > 0 && lastRow + 1 < 14 && gameTable[lastRow + 2][lastColumn] != 1 && gameTable[lastRow + 2][lastColumn + 1] != 1 && gameTable[lastRow + 2][lastColumn - 1] != 1) {
                        lastRow++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow - 1][lastColumn] = 0;
                        matrix[lastRow + 1][lastColumn] = 0;
                        setupGame(type, matrix, 3, destroyer, subMarine, battleShip, carrier);
                    }
                }
            }
            else if (choice == 2 && battleShip != 0) {
                if (type == 'x') {
                    if (lastRow + 1 > 0 && lastRow + 1 < 13 && gameTable[lastRow + 3][lastColumn] != 1 && gameTable[lastRow + 3][lastColumn + 1] != 1 && gameTable[lastRow + 3][lastColumn - 1] != 1) {
                        lastRow++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow - 1][lastColumn] = 0;
                        setupGame(type, matrix, 2, destroyer, subMarine, battleShip, carrier);
                    }
                }
                else {
                    if (lastRow + 1 > 0 && lastRow + 1 < 14 && gameTable[lastRow + 2][lastColumn] != 1 && gameTable[lastRow + 2][lastColumn + 1] != 1 && gameTable[lastRow + 2][lastColumn - 1] != 1) {
                        lastRow++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow - 1][lastColumn] = 0;
                        matrix[lastRow - 2][lastColumn] = 0;
                        setupGame(type, matrix, 2, destroyer, subMarine, battleShip, carrier);
                    }
                }
            }
            else if (choice == 3 && carrier != 0) {
                if (lastRow + 1 > 0 && lastRow + 1 < 14 && gameTable[lastRow + 2][lastColumn] != 1 && gameTable[lastRow + 2][lastColumn + 1] != 1 && gameTable[lastRow + 2][lastColumn - 1] != 1) {
                    lastRow++;
                    matrix[lastRow][lastColumn] = 1;
                    matrix[lastRow - 1][lastColumn] = 0;
                    setupGame(type, matrix, 1, destroyer, subMarine, battleShip, carrier);
                }
            }
            else {
                active1 = true;
                active2 = false;
                setupGame(type, matrix, 0, destroyer, subMarine, battleShip, carrier);
            }
            break;
        case 77: // Right
            if (choice == 0 && destroyer != 0) {
                if (type == 'x') {
                    if (lastColumn + 1 > 0 && lastColumn + 1 < 14 && gameTable[lastRow][lastColumn + 2] != 1 && gameTable[lastRow + 3][lastColumn + 2] != 1 && gameTable[lastRow + 3][lastColumn - 2] != 1 && gameTable[lastRow - 1][lastColumn + 2] != 1 && gameTable[lastRow + 4][lastColumn + 2] != 1) {
                        lastColumn++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn - 1] = 0;
                        setupGame(type, matrix, 4, destroyer, subMarine, battleShip, carrier);
                    }
                }
                else {
                    if (lastColumn + 1 > 0 && lastColumn + 1 < 11 && gameTable[lastRow][lastColumn + 5] != 1 && gameTable[lastRow - 1][lastColumn + 5] != 1 && gameTable[lastRow + 1][lastColumn + 5] != 1) {
                        lastColumn++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn - 1] = 0;
                        matrix[lastRow][lastColumn - 2] = 0;
                        matrix[lastRow][lastColumn - 3] = 0;
                        matrix[lastRow][lastColumn - 4] = 0;
                        setupGame(type, matrix, 4, destroyer, subMarine, battleShip, carrier);
                    }
                }
            }
            else if (choice == 1 && subMarine != 0) {
                if (type == 'x') {
                    if (lastColumn + 1 > 0 && lastColumn + 1 < 14 && gameTable[lastRow][lastColumn + 2] != 1 && gameTable[lastRow + 2][lastColumn + 2] != 1 && gameTable[lastRow + 2][lastColumn - 2] != 1 && gameTable[lastRow - 1][lastColumn + 2] != 1 && gameTable[lastRow + 3][lastColumn + 2] != 1) {
                        lastColumn++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn - 1] = 0;
                        setupGame(type, matrix, 3, destroyer, subMarine, battleShip, carrier);
                    }
                }
                else {
                    if (lastColumn + 1 > 0 && lastColumn + 1 < 12 && gameTable[lastRow][lastColumn + 4] != 1 && gameTable[lastRow - 1][lastColumn + 4] != 1 && gameTable[lastRow + 1][lastColumn + 4] != 1) {
                        lastColumn++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn - 1] = 0;
                        matrix[lastRow][lastColumn - 2] = 0;
                        matrix[lastRow][lastColumn - 3] = 0;
                        setupGame(type, matrix, 3, destroyer, subMarine, battleShip, carrier);
                    }
                }
            }
            else if (choice == 2 && battleShip != 0) {
                if (type == 'x') {
                    if (lastColumn + 1 > 0 && lastColumn + 1 < 14 && gameTable[lastRow][lastColumn + 2] != 1 && gameTable[lastRow + 2][lastColumn + 2] != 1 && gameTable[lastRow + 2][lastColumn - 2] != 1 && gameTable[lastRow - 1][lastColumn + 2] != 1 && gameTable[lastRow + 2][lastColumn + 2] != 1) {
                        lastColumn++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn - 1] = 0;
                        setupGame(type, matrix, 2, destroyer, subMarine, battleShip, carrier);
                    }
                }
                else {
                    if (lastColumn + 1 > 0 && lastColumn + 1 < 13 && gameTable[lastRow][lastColumn + 3] != 1 && gameTable[lastRow - 1][lastColumn + 3] != 1 && gameTable[lastRow + 1][lastColumn + 3] != 1) {
                        lastColumn++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn - 1] = 0;
                        matrix[lastRow][lastColumn - 2] = 0;
                        matrix[lastRow][lastColumn - 3] = 0;
                        setupGame(type, matrix, 2, destroyer, subMarine, battleShip, carrier);
                    }
                }
            }
            else if (choice == 3 && carrier != 0 && gameTable[lastRow][lastColumn + 2] != 1 && gameTable[lastRow + 2][lastColumn + 2] != 1 && gameTable[lastRow + 2][lastColumn - 2] != 1 && gameTable[lastRow - 1][lastColumn + 2] != 1 && gameTable[lastRow + 1][lastColumn + 2] != 1) {
                if (lastColumn + 1 > 0 && lastColumn + 1 < 14 && gameTable[lastRow][lastColumn + 2] != 1 && gameTable[lastRow + 2][lastColumn + 2] != 1) {
                    lastColumn++;
                    matrix[lastRow][lastColumn] = 1;
                    matrix[lastRow][lastColumn - 1] = 0;
                    setupGame(type, matrix, 1, destroyer, subMarine, battleShip, carrier);
                }
            }
            else {
                active1 = true;
                active2 = false;
                setupGame(type, matrix, 0, destroyer, subMarine, battleShip, carrier);
            }
            break;
        case 75: // Left
            if (choice == 0 && destroyer != 0) {
                if (lastColumn - 1 > 0 && lastColumn - 1 < 14 && gameTable[lastRow][lastColumn - 2] != 1 && gameTable[lastRow + 3][lastColumn - 2] != 1 && gameTable[lastRow + 3][lastColumn + 2] != 1 && gameTable[lastRow - 1][lastColumn - 2] != 1 && gameTable[lastRow + 4][lastColumn - 2] != 1) {
                    if (type == 'x') {
                        lastColumn--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn + 1] = 0;
                        setupGame(type, matrix, 4, destroyer, subMarine, battleShip, carrier);
                    }
                    else {
                        lastColumn--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn + 1] = 0;
                        matrix[lastRow][lastColumn + 2] = 0;
                        matrix[lastRow][lastColumn + 3] = 0;
                        matrix[lastRow][lastColumn + 4] = 0;
                        setupGame(type, matrix, 4, destroyer, subMarine, battleShip, carrier);
                    }
                }
            }
            else if (choice == 1 && subMarine != 0) {
                if (lastColumn - 1 > 0 && lastColumn - 1 < 14 && gameTable[lastRow][lastColumn - 2] != 1 && gameTable[lastRow + 2][lastColumn - 2] != 1 && gameTable[lastRow + 2][lastColumn + 2] != 1 && gameTable[lastRow - 1][lastColumn - 2] != 1 && gameTable[lastRow + 3][lastColumn - 2] != 1) {
                    if (type == 'x') {
                        lastColumn--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn + 1] = 0;
                        setupGame(type, matrix, 3, destroyer, subMarine, battleShip, carrier);
                    }
                    else {
                        lastColumn--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn + 1] = 0;
                        matrix[lastRow][lastColumn + 2] = 0;
                        matrix[lastRow][lastColumn + 3] = 0;
                        setupGame(type, matrix, 3, destroyer, subMarine, battleShip, carrier);
                    }
                }
            }
            else if (choice == 2 && battleShip != 0) {
                if (lastColumn - 1 > 0 && lastColumn - 1 < 14 && gameTable[lastRow][lastColumn - 2] != 1 && gameTable[lastRow + 2][lastColumn - 2] != 1 && gameTable[lastRow + 2][lastColumn + 2] != 1 && gameTable[lastRow - 1][lastColumn - 2] != 1 && gameTable[lastRow + 2][lastColumn - 2] != 1) {
                    if (type == 'x') {
                        lastColumn--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn + 1] = 0;
                        matrix[lastRow][lastColumn + 2] = 0;
                        setupGame(type, matrix, 2, destroyer, subMarine, battleShip, carrier);
                    }
                    else {
                        lastColumn--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn + 1] = 0;
                        matrix[lastRow][lastColumn + 2] = 0;
                        setupGame(type, matrix, 2, destroyer, subMarine, battleShip, carrier);
                    }
                }
            }
            else if (choice == 3 && carrier != 0) {
                if (lastColumn - 1 > 0 && lastColumn - 1 < 14 && gameTable[lastRow][lastColumn - 2] != 1 && gameTable[lastRow + 2][lastColumn - 2] != 1 && gameTable[lastRow + 2][lastColumn + 2] != 1 && gameTable[lastRow - 1][lastColumn - 2] != 1 && gameTable[lastRow + 1][lastColumn - 2] != 1) {
                    lastColumn--;
                    matrix[lastRow][lastColumn] = 1;
                    matrix[lastRow][lastColumn + 1] = 0;
                    setupGame(type, matrix, 1, destroyer, subMarine, battleShip, carrier);
                }
            }
            else {
                active1 = true;
                active2 = false;
                setupGame(type, matrix, 0, destroyer, subMarine, battleShip, carrier);
            }
            break;
        case 'r':
            if (type == 'x') type = 'y';
            else type = 'x';
            setupGame(type, matrix, 0, destroyer, subMarine, battleShip, carrier);
        case '\r':
            for (int i = 0; i < 14; i++) {
                for (int j = 0; j < 14; j++) {
                    if (matrix[i][j] == 1) {
                        gameTable[i][j] = 1;
                        cout << i << " | " << j << endl;
                    }
                }
            }
            if (choice == 0) destroyer--;
            else if (choice == 1) subMarine--;
            else if (choice == 2) battleShip--;
            else if (choice == 3) carrier--;
            active1 = true;
            active2 = false;
            if (destroyer == 0 && flagint == 0) {
                flagint = 1;
                choice = 1;
            }
            else if (subMarine == 0 && flagint == 1) {
                flagint = 2;
                choice = 2;
            }
            else if (battleShip == 0 && flagint == 2) {
                flagint = 3;
                choice = 3;
            }
            else if (carrier == 0 && flagint == 3) {
                flagint = 5;
                choice = 5;
            }
            setupGame(type, matrix, 0, destroyer, subMarine, battleShip, carrier);
            break;
        default: break;
        }
    }
    return 0;
}

int gameRow = 7, gameCol = 7;

int enemyDestroyer = 1, enemySubMarine = 2, enemyBattleShip = 3, enemyCarrier = 4;
void CreateEnemy() {
    srand(time(0));
    bool flag = true;
    while (flag) {
        int random = 1 + (rand() % 14);
        int randomX = 1 + (rand() % 14);
        int randomY = 1 + (rand() % 14);
        if (random > 7) {
            if (enemyDestroyer != 0) {
                if (enemyTable[randomX][randomY] != 1 && enemyTable[randomX + 1][randomY] != 1 && enemyTable[randomX + 2][randomY] != 1 && enemyTable[randomX + 3][randomY] != 1) {
                    enemyTable[randomX][randomY] = 1;
                    enemyTable[randomX + 1][randomY] = 1;
                    enemyTable[randomX + 2][randomY] = 1;
                    enemyTable[randomX + 3][randomY] = 1;
                    enemyDestroyer--;
                }
            }
            else if (enemySubMarine != 0) {
                if (enemyTable[randomX][randomY] != 1 && enemyTable[randomX + 1][randomY] != 1 && enemyTable[randomX + 2][randomY] != 1) {
                    enemyTable[randomX][randomY] = 1;
                    enemyTable[randomX + 1][randomY] = 1;
                    enemyTable[randomX + 2][randomY] = 1;
                    enemySubMarine--;
                }
            }
            else if (enemyBattleShip != 0) {
                if (enemyTable[randomX][randomY] != 1 && enemyTable[randomX + 1][randomY] != 1) {
                    enemyTable[randomX][randomY] = 1;
                    enemyTable[randomX + 1][randomY] = 1;
                    enemyBattleShip--;
                }
            }
            else if (enemyCarrier != 0) {
                if (enemyTable[randomX][randomY] != 1) {
                    enemyTable[randomX][randomY] = 1;
                    enemyCarrier--;
                }
            }
            else {
                flag = false;
            }
        }
        else {
            if (enemyDestroyer != 0) {
                if (enemyTable[randomX][randomY] != 1 && enemyTable[randomX][randomY + 1] != 1 && enemyTable[randomX][randomY + 2] != 1 && enemyTable[randomX][randomY + 3] != 1) {
                    enemyTable[randomX][randomY] = 1;
                    enemyTable[randomX][randomY + 1] = 1;
                    enemyTable[randomX][randomY + 2] = 1;
                    enemyTable[randomX][randomY + 3] = 1;
                    enemyDestroyer--;
                }
            }
            else if (enemySubMarine != 0) {
                if (enemyTable[randomX][randomY] != 1 && enemyTable[randomX][randomY + 1] != 1 && enemyTable[randomX][randomY + 2] != 1) {
                    enemyTable[randomX][randomY] = 1;
                    enemyTable[randomX][randomY + 1] = 1;
                    enemyTable[randomX][randomY + 2] = 1;
                    enemySubMarine--;
                }
            }
            else if (enemyBattleShip != 0) {
                if (enemyTable[randomX][randomY] != 1 && enemyTable[randomX][randomY + 1] != 1) {
                    enemyTable[randomX][randomY] = 1;
                    enemyTable[randomX][randomY + 1] = 1;
                    enemyBattleShip--;
                }
            }
            else if (enemyCarrier != 0) {
                if (enemyTable[randomX][randomY] != 1) {
                    enemyTable[randomX][randomY] = 1;
                    enemyCarrier--;
                }
            }
            else {
                flag = false;
            }
        }
    }

}

char turn = 'p';
bool found = false;
int foundX = 0, foundY = 0;

void PlayGame(int startedGame[14][14], char _turn = 'p') {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int size = 15;
    int tempX = 0;
    int tempY = 0;
    cout << "Debug Area: " << endl;

    cout << "Enemy Area: " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || j == 0 || i == size - 1 || j == size - 1) {
                SetConsoleTextAttribute(hConsole, 11);
                cout << "* ";
            }
            else if (startedGame[i][j]) {
                SetConsoleTextAttribute(hConsole, 12);
                cout << char(startedGame[i][j]) << " ";
                SetConsoleTextAttribute(hConsole, 11);
            }
            else if (enemyTable[i][j] == 254 || enemyTable[i][j] == 248) {
                SetConsoleTextAttribute(hConsole, 12);
                cout << char(enemyTable[i][j]) << " ";
                SetConsoleTextAttribute(hConsole, 11);
            }
            else cout << "# ";

        }
        cout << endl;
    }
    cout << "Your Area: " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || j == 0 || i == size - 1 || j == size - 1) {
                SetConsoleTextAttribute(hConsole, 11);
                cout << "* ";
            }
            else if (gameTable[i][j]) {
                SetConsoleTextAttribute(hConsole, 12);
                cout << char(gameTable[i][j]) << " ";
                SetConsoleTextAttribute(hConsole, 11);
            }
            else cout << "# ";

        }
        cout << endl;
    }
    if (_turn == 'p') cout << "Player" << endl;
    else cout << "Computer" << endl;
    char c;
    while (true) {
        if (_turn == 'p') {
            switch ((c = _getch())) {
            case 72: // UP
                if (gameRow - 1 > 0) {
                    gameRow--;
                    startedGame[gameRow][gameCol] = 197;
                    startedGame[gameRow + 1][gameCol] = 0;
                    PlayGame(startedGame);
                }
                break;
            case 80: // Down
                if (gameRow + 1 > 0 && gameRow + 1 < 14) {
                    gameRow++;
                    startedGame[gameRow][gameCol] = 197;
                    startedGame[gameRow - 1][gameCol] = 0;
                    PlayGame(startedGame);
                }
                break;
            case 77: // Right
                if (gameCol + 1 > 0 && gameCol + 1 < 14) {
                    gameCol++;
                    startedGame[gameRow][gameCol] = 197;
                    startedGame[gameRow][gameCol - 1] = 0;
                    PlayGame(startedGame);
                }
                break;
            case 75: // Left
                if (gameCol - 1 > 0 && gameCol - 1 < 14) {
                    gameCol--;
                    startedGame[gameRow][gameCol] = 197;
                    startedGame[gameRow][gameCol + 1] = 0;
                    PlayGame(startedGame);
                }
                break;
            case '\r':
                if (enemyTable[gameRow][gameCol] == 1) {
                    cout << "700" << endl;
                    enemyTable[gameRow][gameCol] = 254;
                    PlayGame(startedGame, 'c');
                }
                else {
                    if (enemyTable[gameRow][gameCol] != 254) {
                        if (enemyTable[gameRow][gameCol] != 248) {
                            enemyTable[gameRow][gameCol] = 248;
                            cout << "708" << endl;
                            PlayGame(startedGame, 'c');
                        }
                    }
                }
                break;
            default: break;
            }
        }
        else {
            if (found) {
                int randomm = 1 + (rand() % 14);
                if (randomm > 7) {
                    int randommm = 1 + (rand() % 14);
                    if (randomm > 7) {
                        if (gameTable[foundX + 1][foundY] == 1) {
                            gameTable[foundX + 1][foundY] = 254;
                            PlayGame(startedGame, 'p');
                        }
                        else {
                            found = false;
                            PlayGame(startedGame, 'c');
                        }
                    }
                    else {
                        if (gameTable[foundX - 1][foundY] == 1) {
                            gameTable[foundX - 1][foundY] = 254;
                            PlayGame(startedGame, 'p');
                        }
                        else {
                            found = false;
                            PlayGame(startedGame, 'c');
                        }
                    }

                }
                else {
                    int randommm = 1 + (rand() % 14);
                    if (randomm > 7) {
                        if (gameTable[foundX][foundY + 1] == 1) {
                            gameTable[foundX][foundY + 1] = 254;
                            PlayGame(startedGame, 'p');
                        }
                        else {
                            found = false;
                            PlayGame(startedGame, 'c');
                        }
                    }
                    else {
                        if (gameTable[foundX][foundY - 1] == 1) {
                            gameTable[foundX][foundY - 1] = 254;
                            PlayGame(startedGame, 'p');
                        }
                        else {
                            found = false;
                            PlayGame(startedGame, 'c');
                        }
                    }
                }
            }
            else {
                int randomX = 1 + (rand() % 14);
                int randomY = 1 + (rand() % 14);
                if (gameTable[randomX][randomY] == 1) {
                    foundX = randomX;
                    foundY = randomY;
                    gameTable[randomX][randomY] = 254;
                    found = true;
                    PlayGame(startedGame, 'p');
                }
                else {
                    if (gameTable[gameRow][gameCol] != 254) {
                        if (gameTable[randomX][randomY] != 248) {
                            gameTable[randomX][randomY] = 248;
                            PlayGame(startedGame, 'p');
                        }
                    }
                    else {
                        PlayGame(startedGame, 'c');
                    }
                }
            }
        }
    }
}