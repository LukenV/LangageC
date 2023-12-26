#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf( "This script will calculation the factorial of an integer typed.\n\n" );

    int n = 0;

    printf( "Please type a positive integer : " );
    scanf( "%d", &n );

    printf( "\n" );

    double nextFactorial = 0.0;
    
    int factorial = 1;
    int i=2;

    while ( i <= n && nextFactorial < INT_MAX ) {

        nextFactorial = (double) factorial * i;

        factorial *= i;

        i++;

    }

    if ( nextFactorial > INT_MAX ) {

        printf( "Error : the value of the result of the factorial is greater than the integer max value !\n" );
        return 1;

    }

    printf( "INT_MAX = %d\n", INT_MAX );

    printf( "!%d = %d\n", n, factorial );

    return 0;
}