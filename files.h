#ifndef FILES_H
#define FILES_H
#include "game.h"
#include <string>
using namespace std;

void SaveHighScoreText();
void LoadHighScoreText();

void LoadStatsFromText();
void SaveStatsToText();
void UpdateStats(int score, int food);
void ShowStats();







#endif
