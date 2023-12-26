#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf( "This script will show the decimal and hexadecimal values of the ascii table for each digit and upper characters.\n\n" );

    for ( char character = 'A'; character <= 'Z'; character++ ) {

        printf( "Caractère = '%c'\tcode déc. = %d\tcode hexa. = %x\n", character, character, character );

    };

    printf( "\n" );

    for ( char digit = '1'; digit <= '9'; digit++ ) {

        printf( "Caractère = '%c'\tcode déc. = %d\tcode hexa. = %x\n", digit, digit, digit );

    };

    printf( "\n" );


    return 0;
}