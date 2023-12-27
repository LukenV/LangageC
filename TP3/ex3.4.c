#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf( "This script will filter the numbers into two arrays, one for negative and the other for positive numbers\n" );

    printf( "\n" );

    int n = 1;

    while ( n > 0 ) {

        printf( "Please enter the number of data to be typed : " );

        scanf( "%d", &n );

        printf( "\n" );

        int* inputs = (int*) malloc( n * sizeof( int ) );

        if ( inputs == NULL ) {

            perror( "Error : no such memory\n" );
            exit(1);

        }

        int number = 0;
        int* walkerInputs = inputs;

        while ( walkerInputs - inputs < n ) {

            int position = (int) ( walkerInputs - inputs + 1 );

            printf( "Number n°%d : ", position );

            scanf( "%d", &number );

            *walkerInputs = number;

            printf( "\n" );

            walkerInputs++;

        }

        int* positiveNumbers = (int*) malloc( n * sizeof( int ) );

        if ( positiveNumbers == NULL ) {

            perror( "Error : no such memory\n" );
            exit(1);

        }

        int* negativeNumbers = (int*) malloc( n * sizeof( int ) );

        if ( negativeNumbers == NULL ) {

            perror( "Error : no such memory\n" );
            exit(1);
            
        }

        int countPositive = 0;
        int countNegative = 0;

        int* walkerPositive = positiveNumbers;
        int* walkerNegative = negativeNumbers;

        walkerInputs = inputs;

        while ( walkerInputs - inputs < n ) {

            int number = *walkerInputs;

            if ( number >= 0 ) {

                *walkerPositive = number;
                walkerPositive++;
                countPositive++;

            } else {

                *walkerNegative = number;
                walkerNegative++;
                countNegative++;

            }

            walkerInputs++;

        }

        printf( "\n" );

        walkerPositive = positiveNumbers;
        walkerNegative = negativeNumbers;

        while ( walkerPositive - positiveNumbers < countPositive ) {

            printf( "%d ", *walkerPositive );

            walkerPositive++;

        }

        printf( "\n" );

        while ( walkerNegative - negativeNumbers < countNegative ) {

            printf( "%d ", *walkerNegative );

            walkerNegative++;

        }

        printf( "\n" );

        free(inputs);
        free(positiveNumbers);
        free(negativeNumbers);

    };

    return 0;
}