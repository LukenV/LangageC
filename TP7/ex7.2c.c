#include <stdio.h>
#include <stdlib.h>

void fillArray( int**, int );
void displayArray( int*, int );
void swapTwoIntArray( int**, int** );

int main(int argc, char const *argv[])
{

    printf( "Function 'swapTwoIntArray' :\n" );

    printf( "\n" );

    int size = 3;

    int* intArray1 = (int*) calloc( size, sizeof( int ) );

    if ( intArray1 == NULL ) {

        perror( "Error : no such memory.\n" );
        exit(1);

    }

    printf( "You'll have to type %d integers for the first array.\n", size );

    printf( "\n" );

    fillArray( &intArray1, size );

    int* intArray2 = (int*) calloc( size, sizeof( int ) );

    if ( intArray2 == NULL ) {

        perror( "Error : no such memory.\n" );
        exit(1);
        
    }

    printf( "You'll have to type %d integers for the second array.\n", size );

    printf( "\n" );

    fillArray( &intArray2, size );

    printf( "Before swap:\n" );

    printf( "\n" );

    printf( "First array : " );

    displayArray( intArray1, size );

    printf( "\n" );
    printf( "\n" );

    printf( "Second array : " );

    displayArray( intArray2, size );

    swapTwoIntArray( &intArray1, &intArray2 );

    printf( "\n" );
    printf( "\n" );

    printf( "After swap:\n" );

    printf( "\n" );

    printf( "First array : " );

    displayArray( intArray1, size );

    printf( "\n" );
    printf( "\n" );

    printf( "Second array : " );

    displayArray( intArray2, size );

    printf( "\n" );

    free( intArray1 );
    free( intArray2 );

    return 0;

}

void fillArray( int** intArray, int size ) {

    for ( int i=0; i<size; i++ ) {

        printf( "Please type the integer n°%d/%d : ", i+1, size );

        int integer = 0;

        scanf( "%d", &integer );

        (*intArray)[i] = integer;

        printf( "\n" );
        
    }

}

void displayArray( int* intArray, int size ) {

    printf( "[ " );

    for ( int i=0; i<size; i++ ) {

        if ( i == size - 1 ) {

            printf( "%d ", intArray[i] );

        } else {

            printf( "%d, ", intArray[i] );

        }
        
    }

    printf( "]" );

}

void swapTwoIntArray( int** a, int** b ) {

    int* temp = *a;
    *a = *b;
    *b = temp;

}