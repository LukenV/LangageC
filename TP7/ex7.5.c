#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 15

void printArray( char*, int*, int );
char* readLine();
int loadArray( char**, int, int*, int** );
bool addArray( int**, int*, int*, int );

int main (int argc, char* argv[]) {

    if ( argc == 1 ) {

        perror( "No arguments found.\nPlease type at least one argument.\n" );
        exit(1);

    }

    printf( "This script will take the arguments in the command line, \n" );

    int* integersArray = NULL;
    int integersLogicalSize = 0;
    int integersPhysicalSize = 0;

    char* legend1 = "Before processing :";

    printArray( legend1, integersArray, integersLogicalSize );

    printf( "\n" );

    char* legend2 = "Array of arguments :";
    int argsSize = argc - 1;

    integersLogicalSize = loadArray( argv+1, argsSize, &integersPhysicalSize, &integersArray );

    printArray( legend2, integersArray, integersLogicalSize );

    printf( "\n" );

    printf( "Please type integers to be added to the array (one per ligne ; Ctrl-D to end) : \n" );

    printf( "\n" );

    char* integerRead;

    while ( ( integerRead = readLine() ) != NULL ) {

        

        if ( strlen( integerRead ) == 1 ) {

            continue;

        }

        bool isAdded = addArray( &integersArray, &integersLogicalSize, &integersPhysicalSize, atoi( integerRead ) );

        if ( !isAdded ) {

            perror( "Error : an error occured.\n" );
            free( integerRead );
            exit(1);

        }

        free( integerRead );

    }

    printf( "\n" );

    char* legend3 = "Array filled :";

    printArray( legend3, integersArray, integersLogicalSize );

    free( integersArray );

}

void printArray( char* legend, int* tab, int size ) {

    printf( "%s\n", legend );

    printf( "\n" );

    if ( size == 0 ) {

        printf( "\t[empty array]\n" );

    } else {

        for ( int i=0; i<size; i++ ) {

            printf( "\t%d\n", tab[i] );

        }

    }

}

char* readLine() {

    char line[MAX_LENGTH];

    char* s;

    while ( fgets( line, MAX_LENGTH, stdin ) != NULL ) {

        if ( line[strlen( line )-1] != '\n' ) {

            perror( "Error : line length is too long.\n" );
            return NULL;

        }

        s = (char*) calloc( strlen( line ) + 1, sizeof( char ) );

        line[ strlen( line ) ] = '\0';

        strcpy( s, line );

        return s;

    }

    return NULL;

}

int loadArray( char** words, int wordsCount, int* physicalSize, int** integersArray ) {

    int logicalSize = 0;
    
    for ( int i=0; i<wordsCount; i++ ) {

        int integer = atoi( words[i] );

        bool isAdded = addArray( integersArray, &logicalSize, physicalSize, integer );

        if ( !isAdded ) {

            return -1;

        }

    }

    return logicalSize;
}

bool addArray( int** array, int* logicalSize, int* physicalSize, int integer ) {

    if ( *array == NULL || *physicalSize == 0 ) {

        int defaultSize = 3;

        *array = (int*) calloc( defaultSize, sizeof( int ) );

        if ( *array == NULL ) {

            perror( "Error : no such memory.\n" );
            return false;

        }

        *physicalSize = defaultSize;

    }

    if ( (*logicalSize) == (*physicalSize) ) {

        (*physicalSize) *= 2;

        *array = (int*) realloc( *array, ( *physicalSize ) * sizeof( int ) );

        if ( ( *array ) == NULL ) {

            perror( "Error : no such memory.\n" );
            return false;

        }

    }

    (*array)[*logicalSize] = integer;

    (*logicalSize)++;

    return true;

}