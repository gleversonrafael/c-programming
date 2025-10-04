#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void callMenu(int *playerRoleP);
void game(int playerRole, int (*matrixCode)[3], int (*matrixVisual)[3]);
void verifyCompletion(bool *completed, int *winner);

void playerInput(int playerRole, int (*matrixCode)[3]);
//void botInput();


///////////////////////////////////////////////////////////////////////
int
main(void)
{
    // [1] = X, [2] = O
    int matrixCode[3][3] = {0}, matrixVisual[3][3] = {0};
    int playerRole;

    playerRole = 1;

    // callMenu(&playerRole);
    game(playerRole, matrixCode, matrixVisual);

    exit(EXIT_SUCCESS);
}

///////////////////////////////////////////////////////////////////////
void 
callMenu(int *playerRoleP) 
{
    char playerRoleC; // C = char && P = pointer

    printf("Welcome to Tic-Tac-Toe in C. \nSelect a role [X or O]:\nANSW: ");

    while(playerRoleC != 'O' && playerRoleC != 'X')
    {
        scanf(" %c", &playerRoleC);
    
        if(playerRoleC != 'O' && playerRoleC != 'X') 
            printf("Please press O or X.\n ANSW: ");
    }

    *playerRoleP = 
    playerRoleC == 'X' ? 1 : 2;   
}

///////////////////////////////////////////////////////////////////////
void
game(int playerRole, int (*matrixCode)[3], int (*matrixVisual)[3]) 
{
    bool completed = false;
    int winner;

    printf("Game has started.\n");

    while(!completed)
    {
        playerInput(playerRole, matrixCode);
        verifyCompletion(&completed, &winner);

        //botInput();
    }
}
///////////////////////////////////////////////////////////////////////

void 
playerInput(int playerRole, int (*matrixCode)[3]) 
{
    bool inserted = false;

    while(!inserted)
    {
        int line, column;

        printf("Select a line and column (format: [L][C], where [0 < L, C < 3] ) \n");
        scanf(" [%d][%d]", &line, &column);

        if(line >= 3 || column >= 3) {
            printf("\n[%d][%d] doesn't exist.\n", line, column);
            continue;
        }

        if(matrixCode[line][column] == 0) 
        {
            matrixCode[line][column] = playerRole;
            inserted = true;
        
        } else 
            printf("\n[%d][%d] has been already selected!\n", line, column);
        
    }
}

void
verifyCompletion(bool *completed, int *winner)
{
    
}
