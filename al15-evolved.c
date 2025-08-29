//ADAPT TO NxM WITH ARRAY POINTERS
//MATRIX[I].length???
#include <stdio.h>
#include <stdlib.h>

// CONSTANTS
#define LINES 5
#define COLUMNS 5

// DECLARATIONS
unsigned short int callNumberInsertion(long double matrix[][COLUMNS], unsigned short int inserted);
void showMatrix(long double matrix[][COLUMNS]);

void positionsOfN(long double matrix[][COLUMNS], long double n);
_Bool returnTrueIfN(unsigned short int line, unsigned short column);

// MAIN FUNCTION
int
main(void) 
{
    long double mainMatrix[LINES][COLUMNS] = {0};
    unsigned short int inserted = 0, selectedLine, selectedColumn;

    char selectedOption;

    // operations...
    do {
        //E
        printf("Select one option: \n [N] Insert number \n [M] Show matrix \n\n [E] = How many primes \n [I] = Searches element and returns true if it exists in the matrix. \n [J] = Returns how many times an element appears. \n [K] Returns all positions of an element. \n [X] Exit program.");

        printf("\n\nSelected option: ");
        scanf("\n%c", &selectedOption);

        //P + S...
        switch(selectedOption) {
            case 'N':
                inserted = callNumberInsertion(mainMatrix, inserted);
                break;

            case 'M':
                showMatrix(mainMatrix);
                break;

            case 'E': break;

            case 'I':
                printf("[line][column]:  ");
                scanf("\n[%hu][%hu]", &selectedLine, &selectedColumn);
                returnTrueIfN(selectedLine, selectedColumn);

                break;

            case 'J':
            case 'K':
            
            default:
                break;
        }

        if(selectedOption != 'X') {
            printf("\nContinue ? [X to exit]:  ");
            scanf("\n%c", &selectedOption);
            printf("\n");
        }

    } while(selectedOption != 'X');

    exit(EXIT_SUCCESS);
}


/// OTHER FUNCTIONS
//[N]
unsigned short int
callNumberInsertion(long double matrix[][COLUMNS], unsigned short int inserted) 
{
    long double number;

    printf("Number: ");
    scanf("%Lf", &number);


    matrix[(int)inserted / COLUMNS][inserted % COLUMNS] = number;


    return ++inserted;
}

//[M]
void
showMatrix(long double matrix[][COLUMNS])
{
    for(int i = 0; i < LINES; i++) {
        for(int j = 0; j < COLUMNS; j++) 
            if(matrix[i][j]) {
                printf("(%-3.0Lf)\t", matrix[i][j]);

            } else {
                printf("(...)\t");
            }
        ;

        printf("\n");
    }
}

// [I, J, K] complementary
void
positionsOfN(long double matrix[][COLUMNS], long double n)
{
    int line = 0, column = 0;
    
    for(;line < LINES; line++) 
        for(;column < COLUMNS; column++)

        ;
    ;
}