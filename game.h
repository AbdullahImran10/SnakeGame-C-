#ifndef GAME_H
#define GAME_H

extern int dir;
extern int foodEatenThisGame;
extern bool gameOver;
extern int width;
extern int height;

extern int x, y;
extern int fruitX, fruitY;
extern int score;

extern int* tailX;
extern int* tailY;
extern int tailLength;

void InitGame();
void InitSnake();
void InitFruit();
void InitScore();
void ResetGame();



#endif
