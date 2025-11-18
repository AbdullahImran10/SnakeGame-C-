#include<iostream>
#include<windows.h>
#include "draw.h"
#include "game.h"

using namespace std;

void ClearScreen(){
    system("cls");
}

void DrawBorder(){
    for(int i=0;i<width+2;i++)
    cout<<"#";
cout<<endl;
}

void DrawSnake(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(j==0)
            cout<<"#";

            if(i==y && j==x)
            cout<<"O";
            else if(i==fruitY && j==fruitX)
            cout<<"F";
            else{
                bool printed=false;

                for(int k=0;k<tailLength;k++){
                    if(tailX[k]==j && tailY[k]==i){
                        cout<<"o";
                        printed=true;
                        break;

                    }
                }

                if(!printed)
                cout<<" ";
            }

            if(j==width-1)
            cout<<"#";
        }
        cout<<endl;
    }
}

void DrawScore(){
    cout<<"Score: "<<score<<endl;
}

void DrawGame(){
    ClearScreen();
    DrawBorder();
    DrawSnake();
    DrawBorder();
    DrawScore();
}