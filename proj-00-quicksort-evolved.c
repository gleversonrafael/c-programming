#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;

#define ARRAY_LENGTH 7
#define true 1
#define false 0


void sortWithQuicksort(boolean leftPartition, boolean rightPartition, double array[], unsigned short int low, unsigned short int high);
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

    sortWithQuicksort(true, true, mainArray, 0, ARRAY_LENGTH - 1);
    outputArray(mainArray);

    return 0;
}


void
sortWithQuicksort(boolean leftPartition, boolean rightPartition, double array[], unsigned short int low, unsigned short high)
{
    //E
    unsigned short int hole = low;
    double outside = array[low];

    //P 
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

    finish:array[hole] = outside;

    //O
    if(leftPartition == true && high - 1 > low)
    {
        sortWithQuicksort(true, false, array, 0, high - 1);
    }

    if(rightPartition == true && low + 1 < high)
    {
        sortWithQuicksort(false, true, array, low + 1, ARRAY_LENGTH);        
    }
}


void outputArray(double array[])
{
    printf("In sorted order: \n");

    for(int this = 0; this < ARRAY_LENGTH; this++)
        printf("|%.0lf|  ", array[this]);
    ;

    printf("\n");
}