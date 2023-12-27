#include <stdlib.h>
#include <stdio.h>
#define SIZE_MAX 9
#define COUNT_OF_LETTERS 26

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

    char matrice1[SIZE_MAX][SIZE_MAX];

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

    char matrice2[SIZE_MAX][SIZE_MAX];

    int min = (int) 'A';
    int max = (int) 'Z';

    // Fill the matrice2 column by column

    for ( int i=0; i<width; i++ ) {

        for ( int j=0; j<height; j++ ) {

            int randomInt = min + (int) ( rand() / ( RAND_MAX+1.0 ) * ( max-min+1 ) );
            char randomLetter = (char) randomInt;

            matrice2[j][i] = randomLetter;


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

    int frequencies[SIZE_MAX][COUNT_OF_LETTERS] = {0};

    int valueOfFirstLetter = (int) 'A';

    for ( int i=0; i<height; i++ ) {

        for ( int j=0; j<width; j++ ) {

            int letter = (int) matrice2[i][j];
            int letterIndex = letter - valueOfFirstLetter;
            frequencies[i][letterIndex]++;

        }

    }

    printf( "           A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n\n" );

    for ( int i=0; i<height; i++ ) {

        printf( "Line n°%d : ", i+1 );

        for ( int j=0; j<COUNT_OF_LETTERS; j++ ) {

            printf( "%d ", frequencies[i][j] );

        }

        printf( "\n" );

    }
    
    return 0;
}