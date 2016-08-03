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


void RunGameMulti() {
    
    int GameOver = 0;
    int scan1 , scan2;
    int Move = 0;
    int board[25];
    int draw = 0;
    char user1[50];
    char user2[50];
    
    
    InitialiseBoard(&board[0]);
    PrintBoard(&board[0]);
    
    printf("Enter your Name User1 : ");
    scanf("%s",&user1);
    
    printf("\nEnter your Name User2 : ");
    scanf("%s",&user2);
    
    for (GameOver=0; GameOver < 9; ++GameOver) {
        
        
        if(Move==0){
            
            printf("\n %s : ",user1);
            scanf("%d", &scan1);
            if (scan1>=9 || scan1<=-1 || (board[ConvertTo25[scan1]])==CROSSES || (board[ConvertTo25[scan1]])==NOUGHTS) {
                printf("Please enter a valid choice");
                GameOver--;
            }
            else{
            board[ConvertTo25[scan1]] = NOUGHTS;
            system("clear");
            Move=1;
            }
        }
        else{
            
            printf("\n %s : ",user2);
            scanf("%d", &scan2);
            if (scan2>=9 || scan2<=-1 || (board[ConvertTo25[scan2]])==CROSSES || (board[ConvertTo25[scan2]])==NOUGHTS) {
                printf("Please enter a valid choice");
                GameOver--;
            }
            else
            {
            
            board[ConvertTo25[scan2]] = CROSSES;
            system("clear");
            Move=0;
            }
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
    
    int choice;
    int back;
start:
    system("clear");

    printf("\nWelcome to TIC-TAC-TOE");
    
    printf("\n\n1. Single Player");
    printf("\n2. Multi Player");
    printf("\n3. Instructions");
    printf("\n4. Exit");
    printf("\n\nEnter a choice : ");
    
    scanf("%d",&choice);
    switch (choice) {
        case 1:
            system("clear");
            printf("\n\nUnder Development :-(");
            printf("\n\nPress any key to go to main menu");
            scanf("%d",&back);
            goto start;
            break;
        
        case 2:
            system("clear");
            RunGameMulti();
            printf("\n\nPress any key to go to main menu");
            scanf("%d",&back);
            goto start;
            break;
        
        case 3:
            system("clear");
            printf("\nInstructions");
            printf("\n\nThe Board Input is of the following arrangement :");
            printf("\n0   1    2");
            printf("\n3   4    5");
            printf("\n6   7    8");
            printf("\n\nPress any key to go to main menu");
            scanf("%d",&back);
            goto start;
            break;
            
        case 4:
            exit(0);
            break;
        
        default:
            printf("\nPlease Enter a valid choice");
            printf("\n\nPress any key to go to main menu");
            scanf("%d",&back);
            goto start;
            
            break;
    }
    
    
    return 0;
}