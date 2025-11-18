#include<iostream>
#include<cstdlib>
#include "game.h"


bool gameOver;
int width=20;
int height=20;

int x,y;
int fruitX,fruitY;
int score;


int dir = 0;  
int foodEatenThisGame=0;


int* tailX=nullptr;
int* tailY=nullptr;
int tailLength=0;

void InitGame(){
    foodEatenThisGame=0;
    gameOver=false;
    InitSnake();
    InitFruit();
    InitScore();
}

void InitSnake(){
    x=width/2;
    y=height/2;

    tailLength=0;
    tailX=new int[200];
    tailY=new int[200];
}

void InitFruit(){
    fruitX=rand()%width;
    fruitY=rand()%height;
}

void InitScore(){
    score=0;
}

void ResetGame(){
    delete[] tailX;
    delete[] tailY;
}


