#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf( "This script will simulate the Euclidean division operation of two strictly positives integers typed.\n\n" );

    int integer1 = 0;
    int integer2 = 0;
    int min = 0;
    int max = 0;

    while ( integer1 <= 0 || integer2 <= 0 ) {

        printf( "\n" );
        printf( "Please type the first integer : " );
        scanf( "%d", &integer1 );

        printf( "\n" );
        printf( "Please type the second integer : " );
        scanf( "%d", &integer2 );

        if ( integer2 > integer1  ) {

            min = integer1;
            max = integer2;

        } else if ( integer1 > integer2 || integer1 == integer2 ) {

            min = integer2;
            max = integer1;

        }

        if ( integer1 <= 0 || integer2 <= 0 ) {

            printf( "\n" );
            printf( "The first and/or the second integer isn't striclty positive.\nPlease enter two new values.\n" );

        }

    }

    printf( "\n" );

    printf( "Starting the simulation of the Euclidean division operation :\n\n" );

    printf( "The min value found : %d\n", min );
    printf( "The max value found : %d\n", max );

    printf( "\n" );

    int currentNumber = 0;
    int quotient = 0;

    while ( (currentNumber + min) < max ) {

        currentNumber += min;
        quotient++;

    }

    int remainder = max - currentNumber;

    printf( "The quotient found : %d\n", quotient );
    printf( "The remainder found : %d\n", remainder );

    printf( "\n" );

    return 0;
}