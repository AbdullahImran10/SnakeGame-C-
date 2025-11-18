#include<windows.h>
#include "game.h"
#include "input.h"
#include "logic.h"
#include "draw.h"


void MoveSnake(){

    for(int i=tailLength-1;i>0;i--){
        tailX[i]=tailX[i-1];
        tailY[i]=tailY[i-1];
    }
    tailX[0]=x;
    tailY[0]=y;
     switch(dir) {
        case 1: x--; break; 
        case 2: x++; break; 
        case 3: y--; break; 
        case 4: y++; break; 
    }
}

void UpdateTail(){

}

void CheckFruitCollision(){
    if(x==fruitX && y==fruitY){
        score+=10;
        foodEatenThisGame++;
        fruitX=rand()%width;
        fruitY=rand()%height;
        tailLength++;
         InitFruit();
    }
}

void CheckWallCollision(){
    if(x<0 || x>=width || y<0 || y>=height)
    gameOver=true;
}

void GameLoop(int difficulty){
    int delay;

    if(difficulty == 1) delay = 150; //EASY
    else if(difficulty == 2) delay = 100; //MEDIUM
    else delay = 60; //HARD

    while(!gameOver){
        DrawGame();
        ProcessInput();
        MoveSnake();
        CheckFruitCollision();
        CheckWallCollision();

        Sleep(delay);  
    }
}

