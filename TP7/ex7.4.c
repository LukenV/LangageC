#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char** copyArgs( char**, int, int* );
void sort( char**, int );
void swapTwoString( char**, char** );
void display( char**, int );

int main (int argc, char* argv[]) {

    if ( argc == 1 ) {

        perror( "No arguments found.\nPlease type at least one argument.\n" );
        exit(1);

    }

    // Deep copy of script arguments

    printf( "This script will take the arguments in the command line,\n" );
    printf( "then it will remove the duplicates arguments, and finally\n" );
    printf( "it will sort alphabetically these arguments.\n" );

    int argsSize = argc - 1;
    int reelSize = 0;
    char** argsArray = copyArgs( argv+1, argsSize, &reelSize );

    printf( "\n" );

    // Display of the array

    printf( "Here is the array of arguments without duplicate :\n" );

    printf( "\n" );

    display( argsArray, reelSize );

    // Sorting the array

    sort( argsArray, reelSize );

    // Display of sorted array

    printf( "\n" );

    printf( "Here is the sorted array of arguments :\n" );

    printf( "\n" );

    display( argsArray, reelSize );

    // Freeing the dynamic memory

    for ( int i=0; i<reelSize; i++ ) {

        free( argsArray[i] );

    }

    free( argsArray );

}

/**
 * PRE: tab: array with n strings
 * POST: *ncp: count of strings in the returned array
 * RES: return an array containing strings' tab without duplicate
 *      (logical size = physical size); NULL sif an error occured.
 */
char** copyArgs( char** tab, int n, int* ncp ) {

    char** argsArray = (char**) calloc( n, sizeof( char* ) );

    if ( argsArray == NULL ) return NULL;

    int indexArgs = 0;

    bool isPresent = false;

    for ( int i=0; i<n; i++ ) {

        const char* word = tab[i];

        for ( int j=0; j<indexArgs; j++ ) {

            if ( strcmp( argsArray[j], word ) == 0 ) {

                isPresent = true;
                break;

            }

        }

        if ( !isPresent ) {

            int wordLength = strlen( word );

            argsArray[indexArgs] = (char*) calloc( ( wordLength + 1 ), sizeof( char ) );

            if ( argsArray[indexArgs] == NULL ) return NULL;

            strcpy( argsArray[indexArgs], word );

            indexArgs++;

        }

        isPresent = false;

    }

    // realloc only if at least one duplicate was found

    if ( *ncp != n ) {

        argsArray = (char**) realloc( argsArray, n * sizeof( char* ) );

    }

    *ncp = indexArgs;

    return argsArray;

}

/**
 * PRE: tab: array with n strings
 * POST: the n strings of tab are sorted by alphabetic order
 *       (algorithm: selection sort)
 */
void sort ( char** tab, int n ) {

    for ( int i=0; i<=n-2; i++ ) {

        int min = i;

        for ( int j=i+1; j <= n-1; j++ ) {

            if ( strcmp( tab[j], tab[min] ) < 0 ) {

                min = j;

            }

        }

        if ( min != i ) {

            swapTwoString( &tab[i], &tab[min] );

        }

    }

}

void swapTwoString( char** string1, char** string2 ) {

    char* temp = *string1;
    *string1 = *string2;
    *string2 = temp;

}

/**
 * PRE: tab: array with n strings
 * POST: display the strings of tab (one string per line,
 *       preceded by their number)
 */
void display( char** tab, int n ) {

   for ( int i=0; i<n; i++ ) {

        printf( "%d) %s\n", i+1, tab[i]  );

    }

}
