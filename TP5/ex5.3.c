#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define COUNT_CHAR 254
#define COUNT_CHESTS 5
#define ID_SIZE 5

int main(int argc, char const *argv[])
{
    printf( "This script allows you to create chests and place contents in them.\n" );
    printf( "You'll have to mention the id of the chest (5 char.) and then the content.\n" );

    printf( "\n" );

    printf( "Example : Ches1 50 gold ingots 1 pure diamond 1 iron sword\n" );

    printf( "\n" );


    int logicalSize = 0;
    int physicalSize = COUNT_CHESTS;

    char** chests = (char**) malloc( physicalSize * sizeof( char* ) );

    if ( chests == NULL ) {

        perror( "Error : no such memory" );
        exit(1);

    }


    for ( int i=0; i<physicalSize; i++ ) {

        chests[i] = (char*) calloc( COUNT_CHAR + 2, sizeof( char ) );

        if ( chests[i] == NULL ) {

            perror( "Error : no such memory" );
            exit(1);

        }
        
    }

    printf( "Please type the id of the chest and then its content (Ctrl-D to end the script) :\n" );

    printf( "\n" );

    char line[COUNT_CHAR+2];

    while( fgets( line, COUNT_CHAR+2, stdin ) != NULL ) {

        bool isNewChest = true;
        int chestIndex = -1;

        int lineLength = strlen( line );

        for ( int i=0; i<logicalSize; i++ ) {

            if ( strncmp( line, chests[i], 5 ) == 0 ) {

                isNewChest = false;
                chestIndex = i;

            }

        }

        if ( isNewChest ) {

            if ( logicalSize == physicalSize ) {

                physicalSize *= 2;

                chests = (char**) realloc( chests, physicalSize * sizeof( char* ) );

                if ( chests == NULL ) {

                    perror( "Error : no such memory" );
                    exit(1);

                }

                for ( int i=logicalSize; i<physicalSize; i++ ) {

                    chests[i] = (char*) calloc( COUNT_CHAR + 2, sizeof( char ) );

                    if ( chests[i] == NULL ) {

                        perror( "Error : no such memory" );
                        exit(1);

                    }
                    
                }

            }

            line[lineLength-1] = '\0';

            strcat( chests[logicalSize], line );

            // Plus 1 for the '\0'

            chests[logicalSize] = (char*) realloc( chests[logicalSize], ( lineLength ) * sizeof( char ) );

            if ( chests[logicalSize] == NULL ) {

                perror( "Error : no such memory" );
                exit(1);

            }

            logicalSize++;


        } else {

            int chestLength = strlen( chests[chestIndex] );

            int newChestLength = ( chestLength + lineLength );

            chests[chestIndex] = (char*) realloc( chests[chestIndex], newChestLength * sizeof( char ) );

            if ( chests[chestIndex] == NULL ) {

                perror( "Error : no such memory" );
                exit(1);

            }

            int lengthContentToAdd = lineLength - ID_SIZE + 1;

            char* chestContentToAdd = (char*) calloc( lengthContentToAdd, sizeof( char ) );

            if ( chestContentToAdd == NULL ) {

                perror( "Error : no such memory" );
                exit(1);

            }

            int indexChar = 0;

            // Minus 1 to remove the '\n'

            for ( int i=ID_SIZE; i<lineLength-1; i++ ) {

                chestContentToAdd[indexChar] = line[i];

                indexChar++;

            }

            strcat( chests[chestIndex], chestContentToAdd );

            free( chestContentToAdd );

        }

    }

    printf( "\n" );

    printf( "Chests :\n\n" );

    for ( int i=0; i<logicalSize; i++ ) {

        printf( "%s\n", chests[i] );
        
    }

    for ( int i=0; i<physicalSize; i++ ) {

        free( chests[i] );
        
    }

    free( chests );

    return 0;
}