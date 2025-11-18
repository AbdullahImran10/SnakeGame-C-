#include <fstream>
#include<iostream>
#include<ctime>
#include "files.h"
#include "game.h"

using namespace std;

int highestScore = 0;
int lastScore = 0;
int totalGames = 0;
int totalFoodEaten = 0;

string lastPlayed = "Never";

void SaveHighScoreText() {
    ofstream file("../data/highscore.txt");
    if(file.is_open())
        file << score;

    file.close();
}

void LoadHighScoreText() {
    ifstream file("../data/highscore.txt");
    if(file.is_open())
        file >> score;
    file.close();
}

void LoadStatsFromText() {
    ifstream fin("../data/stats.txt");
    if (!fin) return;

    fin >> highestScore;
    fin >> lastScore;
    fin >> totalGames;
    fin >> totalFoodEaten;
  
    fin.ignore();
    getline(fin, lastPlayed);

    fin.close();
}

void SaveStatsToText() {
    ofstream fout("../data/stats.txt");

     fout << highestScore << endl;
    fout << lastScore << endl;
    fout << totalGames << endl;
    fout << totalFoodEaten << endl;
  
    fout << lastPlayed << endl;
    fout.close();
}

void UpdateStats(int score, int food) {
    lastScore = score;
    totalGames++;
    totalFoodEaten += food;
   

    if (score > highestScore)
        highestScore = score;

    
    time_t now = time(0);
    lastPlayed = ctime(&now);
    lastPlayed.pop_back();

}

void ShowStats() {
    cout << "\n----- GAME STATS -----\n";
    cout << "Highest Score: " << highestScore << endl;
    cout << "Last Score: " << lastScore << endl;
    cout << "Total Games Played: " << totalGames << endl;
    cout << "Total Food Eaten: " << totalFoodEaten << endl;
    
    cout << "Last Played: " << lastPlayed << endl;
    cout << "-----------------------\n\n";
}

void SaveGameBinary(GameState state) {
    ofstream fout("../data/savegame.bin", ios::binary);
    if (!fout) {
        cout << "Error saving game!\n";
        return;
    }

    fout.write((char*)&state, sizeof(GameState));
    fout.close();

    cout << "Game Saved Successfully!\n";
}




