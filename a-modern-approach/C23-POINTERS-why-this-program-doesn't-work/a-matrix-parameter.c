#include <stdio.h>
#define ROWS 5
#define COLUMNS 4

void printMatrix(int matrix[][COLUMNS]);

int 
main(void)
{
    int app[ROWS][COLUMNS] = {0};
    printMatrix(app);

    return 0;
}


void
printMatrix(int matrix[][COLUMNS]) 
{
    int row = 0, column = 0;

    while(row++ < ROWS) {
        while(column++ < COLUMNS) {
            matrix[row][column] = 1;
            printf("%d\t", matrix[row][column]);            
        }

        printf("\n");
    }
}
