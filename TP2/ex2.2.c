#include <stdlib.h>
#include <stdio.h>
#define SIZEMAX 9

int main(int argc, char const *argv[])
{

    printf( "This script will fill a two dimensions array with the alphabet\n" );

    printf( "\n" );

    printf( "Please enter the height of the array : " );

    int height = 0;

    scanf( "%d", &height );

    printf( "\n" );

    printf( "Please enter the width of the array : " );

    int width = 0;

    scanf( "%d", &width );

    char matrice1[SIZEMAX][SIZEMAX];

    char letter = 'A';

    // Fill the matrice1 line by line

    for ( int i=0; i<height; i++ ) {

        for ( int j=0; j<width; j++ ) {

            matrice1[i][j] = letter;

            if ( letter == 'Z' ) {

                letter = 'A';

            } else {

                letter++;

            }


        }

    }

    char matrice2[SIZEMAX][SIZEMAX];

    letter = 'A';

    // Fill the matrice2 column by column

    for ( int i=0; i<width; i++ ) {

        for ( int j=0; j<height; j++ ) {

            matrice2[j][i] = letter;

            if ( letter == 'Z' ) {

                letter = 'A';

            } else {

                letter++;

            }


        }

    }

    printf( "\n" );

    for ( int i=0; i<height; i++ ) {

        for ( int j=0; j<width; j++ ) {

            if ( matrice1[i][j] == matrice2[i][j] ) {

                printf( "%c in line %d and column %d\n", matrice1[i][j], i, j );

            }

        }

    }
    
    return 0;
}