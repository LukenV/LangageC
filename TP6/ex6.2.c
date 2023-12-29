#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 27

void printArray( char**, int );
bool search( char**, int, char* );
int readAndValidateString( char*, char*, int );

int main(int argc, char const *argv[])
{
    if ( argc == 1 ) {

        perror( "This script needs at least one argument.\n" );
        exit(1);

    }

    printf( "This script will show all the arguments (except the name of the script) and transform them into upper letters words.\n" );

    printf( "\n" );

    // Minus the name of the script (-1)

    int argsSize = argc - 1;

    char** argsArray = (char**) calloc( argsSize, sizeof( char* ) );

    if ( argsArray == NULL ) {

        perror( "Error : no such memory.\n" );
        exit(1);

    }

    int argsIndex = 0;

    for ( int i=1; i<=argsSize; i++ ) {

        int wordSize = strlen( argv[i] );

        argsArray[argsIndex] = (char*) calloc( wordSize + 1, sizeof( char ) );

        if ( argsArray[argsIndex] == NULL ) {

            perror( "Error : no such memory.\n" );
            exit(1);
            
        }

        for ( int j=0; j<wordSize; j++ ) {

            argsArray[argsIndex][j] = argv[i][j];

        }

        argsIndex++;

    }

    printArray( argsArray, argsSize );

    printf( "\n" );

    char line[SIZE+2];

    int countWordsNotFound = 0;

    int wordLength = 0;

    char* inviteString = "Please type a word :\n\n";

    while ( (wordLength = readAndValidateString( inviteString, line, SIZE+2 ) ) != -1 ) {

        printf( "\n" );

        printf( "Word read : %s\nWord length : %d\n", line, wordLength );

        char* wordPresent;

        bool isWordPresent = search( argsArray, argsSize, line );

        if ( isWordPresent ) {

            wordPresent = "present";

        } else {

            wordPresent = "absent";
            countWordsNotFound++;

        }

        printf( "\n" );

        printf( "Word %s is %s.\n", line, wordPresent );

        printf( "\n" );

    }

    printf( "\n" );

    printf( "%d words not found.\n", countWordsNotFound );

    printf( "\n" );

    for ( int i=0; i<argsSize; i++ ) {

        free( argsArray[i] );

    }

    free( argsArray );
    
    return 0;
}

void printArray( char** array, int size ) {

    for ( int i=0; i<size; i++ ) {

        printf( "%d) %s\n", i+1, array[i] );

    }

}

bool search( char** strings, int n, char* word ) {

    bool isPresent = false;

    for ( int i=0; i<n; i++ ) {

        if ( strcasecmp( word, strings[i] ) == 0 ) {

            isPresent = true;
            break;

        }

    }

    return isPresent;

}

int readAndValidateString( char* invite, char* string, int size ) {

    printf( "%s", invite );

    while ( fgets( string, size, stdin ) != NULL ) {

        if ( strlen(string) == 1 ) {

            printf( "The word is empty.\n" );

            continue;

        }

        if ( string[strlen(string)-1] != '\n' ) {

            printf( "The word is too long.\n" );

            while ( fgets( string, size, stdin ) && string[strlen( string )-1] != '\n' );

            continue;

        }

        string[strlen(string)-1] = '\0';

        return strlen(string);

    }

    return -1;

}