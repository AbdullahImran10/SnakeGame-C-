#include <iostream>
#include "menu.h"
#include "game.h"
#include "logic.h"
#include "settings.h"
#include "files.h"  
using namespace std;

void ShowMenu() {
    int choice;
    Settings s;

    do {
        cout << "==== SNAKE GAME MENU ====" << endl;
        cout << "1. Start New Game" << endl;
        cout << "2. Load Settings" << endl;
        cout << "3. Save Settings" << endl;
        cout << "4. Exit" << endl;
        cout << "Select: ";
        cin >> choice;

        switch (choice) {

        case 1:
            s.difficulty = 2; 
            s.boardSize = 20;
           LoadSettingsBinary(s);       
           ApplySettingsToGame(s);     
           InitGame();                  
           GameLoop(s.difficulty);      
           UpdateStats(score,foodEatenThisGame);
           ShowStats();
            break;

        case 2:
            if (LoadSettingsBinary(s)) {
                cout << "Difficulty:  " << s.difficulty << endl;
                cout << "Board Size:  " << s.boardSize << endl;
            }
            break;

        case 3:
            cout << "Enter Difficulty (1=Easy, 2=Medium, 3=Hard): ";
            cin >> s.difficulty;

            cout << "Enter Board Size (20 / 25 / 30 recommended): ";
            cin >> s.boardSize;

            SaveSettingsBinary(s);
            break;

        case 4:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);
}

