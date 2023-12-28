#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#define SIZE 27

int main(int argc, char const *argv[])
{
    if ( argc == 1 ) {

        perror( "This script needs at least one argument.\n" );
        exit(1);

    }

    printf( "This script will show all the arguments (except the name of the script) and transform them into upper letters words.\n" );

    printf( "\n" );

    // Minus the name of the script (-1)

    int countArgs = argc - 1;

    for ( int i=1; i<=countArgs; i++ ) {

        printf( "%d) %s\n", i, argv[i] );

    }

    printf( "\n" );

    char line[SIZE+2];

    int countWordsNotFound = 0;

    while ( fgets( line, SIZE+2, stdin ) != NULL ) {

        printf( "\n" );

        int wordLength = strlen( line ) - 1;

        if ( line[wordLength] != '\n' ) {

            printf( "The word is too long.\n" );

            while ( fgets( line, SIZE+2, stdin ) && line[strlen( line ) - 1] != '\n' );

            continue;
        }

        line[wordLength] = '\0';

        printf( "Word read : %s\nWord length : %d\n", line, wordLength );

        char* wordPresent = "absent";

        for ( int i=1; i<=countArgs; i++ ) {

            if ( strcasecmp( line, argv[i] ) == 0 ) {

                wordPresent = "present";
                break;

            }

        }

        if ( strcmp( wordPresent, "absent" ) == 0 ) {

            countWordsNotFound++;

        }

        printf( "\n" );

        printf( "Word %s is %s.\n", line, wordPresent );

        printf( "\n" );

    }

    printf( "\n" );

    printf( "%d words not found.\n", countWordsNotFound );

    printf( "\n" );
    
    return 0;
}