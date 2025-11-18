#include<conio.h>
#include "input.h"
#include "game.h"

char GetKey(){
    if(_kbhit())
        return _getch();
    return '\0';
}

void ProcessInput() {
    char key = GetKey();
    switch(key) {
        case 'a': dir = 1; break;
        case 'd': dir = 2; break;
        case 'w': dir = 3; break;
        case 's': dir = 4; break;
        default: 
                break;
    }
}

// void ProcessInput() {
//     char key = GetKey();

//     switch(key) {
//         case 'a': {
//             if(dir != 2) dir = 1; // left
//             break;
//         }
//         case 'd': {
//             if(dir != 1) dir = 2; // right
//             break;
//         }
//         case 'w': {
//             if(dir != 4) dir = 3; // up
//             break;
//         }
//         case 's': {
//             if(dir != 3) dir = 4; // down
//             break;
//         }
//         default: break;  // ignore other keys
//     }
// }


