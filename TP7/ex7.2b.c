#include <stdio.h>
#include <stdlib.h>

void swapTwoString( char**, char** );

int main(int argc, char const *argv[])
{

    printf( "Function 'swapTwoString' :\n" );

    printf( "\n" );

    int size = 11;

    char* string1 = (char*) calloc( size, sizeof( char ) );

    if ( string1 == NULL ) {

        perror( "Error : no such memory.\n" );
        exit(1);
        
    }

    printf( "Please type a string (%d char. max) : ", size );

    fgets( string1, size, stdin );

    char* string2 = (char*) calloc( size, sizeof( char ) );

    if ( string2 == NULL ) {

        perror( "Error : no such memory.\n" );
        exit(1);
        
    }

    printf( "Please type a string (%d char. max) : ", size );

    fgets( string2, size, stdin );

    printf( "\n" );

    printf( "Before swap:\n\nstring1 : %s\nstring2 : %s\n", string1, string2 );

    swapTwoString( &string1, &string2 );

    printf( "\n" );

    printf( "After swap :\n\nstring1 : %s\nstring2 : %s\n", string1, string2 );

    printf( "\n" );

    free( string1 );
    free( string2 );

    return 0;
}

void swapTwoString( char** a, char** b ) {

    char* temp = *a;
    *a = *b;
    *b = temp;

}