#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "curses.h"

/*
 Chess Board Idea
	:,:,:,:,:,
	:,O,-,X,:,
	:,X,-,-,:,
	:,-,-,-,:,
	:,:,:,:,:,
 }
 */

enum { NOUGHTS, CROSSES, BORDER, EMPTY };
enum { HUMANWIN, COMPWIN, DRAW };

const int ConvertTo25[9] = {
    6,7,8,
    11,12,13,
    16,17,18
};

void InitialiseBoard(int *board) {
    int index = 0;
    
    for(index = 0; index < 25; ++index) {
        board[index] = BORDER;
    }
    
    for(index = 0; index < 9; ++index) {
        board[ConvertTo25[index]] = EMPTY;
    }
}

void PrintBoard(const int *board) {
    int index = 0;
    char pceChars[] = "OX|-";
    printf("\n\nBoard:\n\n");
    for(index = 0; index < 9; ++index) {
        if(index!=0 && index%3==0) {
            printf("\n\n");
        }
        printf("%4c",pceChars[board[ConvertTo25[index]]]);
    }
    printf("\n");
}

int HasEmpty(const int *board) {
    int index = 0;
    
    for(index = 0; index < 9; ++index) {
        if( board[ConvertTo25[index]] == EMPTY) return 1;
    }
    return 0;
}

void RunGame() {
    
    int GameOver = 0;
    int scan1 , scan2;
    int Move = 0;
    int board[25];
    int draw = 0;
    
    InitialiseBoard(&board[0]);
    PrintBoard(&board[0]);
    
    for (GameOver=0; GameOver < 9; ++GameOver) {
        
        
        if(Move==0){
            scanf("%d", &scan1);
            board[ConvertTo25[scan1]] = NOUGHTS;
            system("clear");
            Move=1;
        }
        else{
            scanf("%d", &scan2);
            board[ConvertTo25[scan2]] = CROSSES;
            system("clear");
            Move=0;
            
        }
        
        PrintBoard(&board[0]);
        if ((board[ConvertTo25[0]] == NOUGHTS && board[ConvertTo25[1]] == NOUGHTS && board[ConvertTo25[2]] == NOUGHTS) || (board[ConvertTo25[3]] == NOUGHTS && board[ConvertTo25[4]] == NOUGHTS && board[ConvertTo25[5]] == NOUGHTS) || (board[ConvertTo25[6]] == NOUGHTS && board[ConvertTo25[7]] == NOUGHTS && board[ConvertTo25[8]] == NOUGHTS) ||
            (board[ConvertTo25[0]] == NOUGHTS && board[ConvertTo25[3]] == NOUGHTS && board[ConvertTo25[6]] == NOUGHTS) ||
            (board[ConvertTo25[1]] == NOUGHTS && board[ConvertTo25[4]] == NOUGHTS && board[ConvertTo25[7]] == NOUGHTS) ||
            (board[ConvertTo25[2]] == NOUGHTS && board[ConvertTo25[5]] == NOUGHTS && board[ConvertTo25[8]] == NOUGHTS) ||
            (board[ConvertTo25[0]] == NOUGHTS && board[ConvertTo25[4]] == NOUGHTS && board[ConvertTo25[8]] == NOUGHTS) ||
            (board[ConvertTo25[2]] == NOUGHTS && board[ConvertTo25[4]] == NOUGHTS && board[ConvertTo25[6]] == NOUGHTS)) {
            
            printf("\n\nUser 1 Wins");
            draw = 1;
            exit(0);
        }
        if ((board[ConvertTo25[0]] == CROSSES && board[ConvertTo25[1]] == CROSSES && board[ConvertTo25[2]] == CROSSES) || (board[ConvertTo25[3]] == CROSSES && board[ConvertTo25[4]] == CROSSES && board[ConvertTo25[5]] == CROSSES) || (board[ConvertTo25[6]] == CROSSES && board[ConvertTo25[7]] == CROSSES && board[ConvertTo25[8]] == CROSSES) ||
            (board[ConvertTo25[0]] == CROSSES && board[ConvertTo25[3]] == CROSSES && board[ConvertTo25[6]] == CROSSES) ||
            (board[ConvertTo25[1]] == CROSSES && board[ConvertTo25[4]] == CROSSES && board[ConvertTo25[7]] == CROSSES) ||
            (board[ConvertTo25[2]] == CROSSES && board[ConvertTo25[5]] == CROSSES && board[ConvertTo25[8]] == CROSSES) ||
            (board[ConvertTo25[0]] == CROSSES && board[ConvertTo25[4]] == CROSSES && board[ConvertTo25[8]] == CROSSES) ||
            (board[ConvertTo25[2]] == CROSSES && board[ConvertTo25[4]] == CROSSES && board[ConvertTo25[6]] == CROSSES)) {
            
            printf("\n\nUser 2 Wins");
            draw = 1;
            exit(0);
        }
        
        
    }
    if (draw==0) {
        printf("\n\nIts a Draw");
    }
    printf("\n\nGame Over");
}

int main() {		
    

    RunGame();
    
    return 0;
}