#include <stdio.h>
#include <stdlib.h>

long double obtainFactorial(long double);

int 
main(void) 
{
    long double factorialResult = 1.0, selectedNumber;
  
    printf("|| Selected number: ");
    scanf("%llf", &selectedNumber);

    factorialResult = obtainFactorial(selectedNumber);

    printf("|| Factorial result: %llf", factorialResult);

    exit(EXIT_SUCCESS);
}

long double 
obtainFactorial(long double n)
{
    if(n <= 1)
        return 1;

    return n*obtainFactorial(n-1);
}