#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH 10

void sortWithQuicksort(double array[], unsigned short int low, unsigned short int high);
void outputArray(double array[]);

int 
main(void)
{
    double mainArray[ARRAY_LENGTH] = {0};
    int current = 0;

    printf("Enter %d numbers to be sorted: ", ARRAY_LENGTH);

    for(; current < ARRAY_LENGTH; current++) 
        scanf("%lf", &mainArray[current])
    ;

    sortWithQuicksort(mainArray, 0, ARRAY_LENGTH - 1);
    outputArray(mainArray);

    return 0;
}

// FINISH....

void
sortWithQuicksort(double array[], unsigned short int low, unsigned short high)
{
    unsigned short int hole = low;
    double outside = array[low];
    
    while(low != high) 
    {
        while(array[high] > outside) 
        {
            high--;

            if(high == low) 
                goto finish;
        }

        array[hole] = array[high];
        hole = high;
        
        while(array[low] <= outside) 
        {
            low++;

            if(high == low) 
                goto finish;
        }

        array[hole] = array[low];
        hole = low;
    }

    finish:array[low] = outside;

    if(low - 1 > 0 && low + 1 < ARRAY_LENGTH)
        sortWithQuicksort(array, low - 1, low + 1);
}


void outputArray(double array[])
{
    printf("In sorted order: \n");

    for(int this = 0; this < ARRAY_LENGTH; this++)
        printf("|%.0lf|  ", array[this]);
    ;

    printf("\n");
}