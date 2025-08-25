//ADAPT TO NxM WITH ARRAY POINTERS
#include <stdio.h>
#include <stdlib.h>

#define LINES 5
#define COLUMNS 5

void callNumberInsertion(long double matrix[][COLUMNS], unsigned short int inserted);

int 
main(void) 
{
    unsigned short int inserted = 0;

    char selectedOption;
    long double mainMatrix[LINES][COLUMNS] = {0};

    // operations...
    do {
        //E
        printf("Select one option: \n [N] Insert number \n [M] Show matrix \n\n [E] = How many primes \n [I] = Searches element and returns true if it exists in the matrix. \n [J] = Returns how many times an element appears. \n [K] Returns position of a element. \n [X] Exit program.");

        printf("\n\nSelected option: ");
        scanf("%c", &selectedOption);

        //P + S...
        switch(selectedOption) {
            case 'N':
                callNumberInsertion(mainMatrix, inserted);

            case 'M':
            case 'E':
            case 'I':
            case 'J':
            case 'K':
            
            default:
                break;
        }

    } while(selectedOption != 'X');

    exit(EXIT_SUCCESS);
}

void
callNumberInsertion(long double matrix[][COLUMNS], unsigned short int inserted) 
{
    long double number;
    unsigned short int line, column;

    printf("Number: ");
    scanf("%llf", &number);

    line = inserted / COLUMNS;
    column = inserted % COLUMNS;

    matrix[line][column] = number;
}