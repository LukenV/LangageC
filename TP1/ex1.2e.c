#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf( "This script will show all the dividers of an strictly positive integer typed.\n\n" );

    int integer;

    printf( "Please type the integer : " );
    scanf( "%d", &integer );

    if ( integer < 1 ) {

        printf( "Error : the integer must be strictly positive. (integer >= 1)\n" );
        return 1;

    }

    printf( "\n" );

    printf( "The list of the dividers of %d :\n\n", integer );

    for ( int i=1; i<=integer; i++ ) {

        if ( integer % i == 0 ) {

            printf( "- %d\n", i );

        }

    }


    return 0;
}