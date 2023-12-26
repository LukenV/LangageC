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

    int factorial = 1;
    double step = 0.0;

    for ( int i=2; i<=n; i++ ) {

        step = (double) factorial * i;

        if ( step > INT_MAX ) {

            printf( "Error : the value of the result of the factorial is greater than the integer max value !\n" );
            return 1;

        }

        factorial = factorial * i;

    }

    printf( "INT_MAX = %d\n", INT_MAX );

    printf( "!%d = %d\n", n, factorial );

    return 0;
}