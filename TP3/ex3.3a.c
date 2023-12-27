#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf( "Please enter the number of data to be typed : " );

    int n = 0;
    
    scanf( "%d", &n );

    printf( "\n" );

    int* inputs = (int*) malloc( n * sizeof( int ) );

    if ( inputs == NULL ) {

        perror( "Error : no such memory\n" );
        exit(1);

    }

    int i = 0;
    int number = 0;

    while ( i < n ) {

        printf( "Number n°%d : ", i+1 );

        scanf( "%d", &number );

        inputs[i] = number;

        printf( "\n" );

        i++;

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

    int indexPositive = 0;
    int indexNegative = 0;

    for ( int i=0; i<n; i++ ) {

        int number = inputs[i];

        if ( number >= 0 ) {

            positiveNumbers[indexPositive] = number;
            indexPositive++;

        } else {

            negativeNumbers[indexNegative] = number;

            indexNegative++;

        }
    }

    printf( "\n" );

    for ( int i=0; i<indexPositive; i++ ) {

        printf( "%d ", positiveNumbers[i] );

    }

    printf( "\n" );

    for ( int i=0; i<indexNegative; i++ ) {

        printf( "%d ", negativeNumbers[i] );

    }

    printf( "\n" );

    free(inputs);
    free(positiveNumbers);
    free(negativeNumbers);

    return 0;
}