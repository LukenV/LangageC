#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    if ( argc == 1 ) {

        perror( "This script needs at least one argument.\n" );
        exit(1);

    }

    printf( "This script will take all the arguments (except the name of the script) and transform them into upper letters words.\n" );

    // Minus the name of the script (-1)

    int countArgs = argc - 1;

    char** upperArgs = (char**) calloc( countArgs, sizeof( char* ) );

    if ( upperArgs == NULL ) {

        perror( "Error : no such memory" );
        exit(1);
        
    }

    int indexUpper = 0;

    for ( int i=1; i <= countArgs; i++ ) {

        int currentArgLength = strlen( argv[i] );

        upperArgs[indexUpper] = (char*) calloc( currentArgLength + 1, sizeof( char ) );

        if ( upperArgs[indexUpper] == NULL ) {

            perror( "Error : no such memory" );
            exit(1);

        }

        for ( int j=0; j<currentArgLength; j++ ) {

            upperArgs[indexUpper][j] = (char) toupper(argv[i][j]);

        }

        indexUpper++;

    }

    for ( int i=0; i < countArgs; i++ ) {

        printf( "%s\n", upperArgs[i] );
        free(upperArgs[i]);

    }

    free(upperArgs);
    
    return 0;
}