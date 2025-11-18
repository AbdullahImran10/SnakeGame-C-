#pragma once
#include <string>

struct Settings {
    int difficulty;   
    int boardSize;            
};

void SaveSettingsBinary(const Settings &s);
bool LoadSettingsBinary(Settings &s);
void ApplySettingsToGame(const Settings &s);   