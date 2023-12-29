#include <stdio.h>
#include <stdlib.h>

void swapTwoInt( int*, int* );
void swapTwoString( char**, char** );

int main(int argc, char const *argv[])
{

    printf( "Function 'swapTwoInt' :\n" );

    printf( "\n" );

    int integer1 = 5;
    int integer2 = 10;

    printf( "Before swap:\n\na : %d\nb : %d\n", integer1, integer2 );

    swapTwoInt( &integer1, &integer2 );

    printf( "\n" );

    printf( "After swap :\n\na : %d\nb : %d\n", integer1, integer2 );

    printf( "\n" );

    return 0;
}

void swapTwoInt( int* a, int* b ) {

    int temp = *a;
    *a = *b;
    *b = temp;

}