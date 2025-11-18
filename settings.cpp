#include "settings.h"
#include<iostream>
#include <fstream>
#include <windows.h>
#include "game.h"   

using namespace std;

void SaveSettingsBinary(const Settings &s) {
    ofstream fout("../data/settings.bin", ios::binary);

    if (!fout) {
        cout << "Error saving settings!" << endl;
        return;
    }

    fout.write((char*)&s, sizeof(Settings));
    fout.close();

    cout << "Settings Saved Successfully!" << endl;
}

bool LoadSettingsBinary(Settings &s) {
    ifstream fin("../data/settings.bin", ios::binary);

    if (!fin) {
        cout << "No saved settings found!" << endl;
        return false;
    }

    fin.read((char*)&s, sizeof(Settings));
    fin.close();

    cout << "Settings Loaded Successfully!" << endl;
    return true;
}

void ApplySettingsToGame(const Settings &s) {
    width  = s.boardSize;
    height = s.boardSize;
    
}
