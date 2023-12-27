#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf( "This script will provide a power 4 game.\n" );

    printf( "\n" );

    printf( "Please enter the height of the grid : " );

    int height = 0;

    scanf( "%d", &height );

    printf( "\n" );

    printf( "Please enter the width of the grid : " );

    int width = 0;

    scanf( "%d", &width );

    printf( "\n" );

    char** matrix = (char**) malloc( height * sizeof( char* ) );

    if ( matrix == NULL ) {

        perror( "Error : no such memory\n" );
        exit(1);

    }

    int* linesIndex = (int*) malloc( width * sizeof( int ) );

    if ( linesIndex == NULL ) {

        perror( "Error : no such memory\n" );
        exit(1);

    }

    for ( int i=0; i<height; i++ ) {

        matrix[i] = (char*) malloc( width * sizeof( char ) );

        if ( matrix[i] == NULL ) {

            perror( "Error : no such memory\n" );
            exit(1);

        }

        // Fill the matrix

        for ( int j=0; j<width; j++ ) {

            linesIndex[i] = height-1;

            matrix[i][j] = '.';

        }

    }

    char player = 'X';
    int position = 1;

    while ( position != 0 ) {

        printf( "Column player %c : ", player );

        scanf( "%d", &position );

        if ( position < 0 || position > width ) {

            int newWidth = 0;

            if ( position < 0 ) {

                newWidth = width + position;

                if ( newWidth <= 0 ) newWidth = 1;

            }

            if ( position > width ) {

                newWidth = position;

            }

            for ( int i=0; i<height; i++ ) {

                matrix[i] = (char*) realloc( matrix[i], newWidth * sizeof( char ) );

                if ( matrix[i] == NULL ) {

                    perror( "Error : no such memory" );
                    exit(1);

                }

            }

            if ( position > width ) {

                // Fill the part added of the matrix

                for ( int i=0; i<height; i++ ) {

                    for ( int j=width; j<newWidth; j++ ) {

                        matrix[i][j] = '.';

                    }

                }

            }

            linesIndex = (int*) realloc( linesIndex, newWidth * sizeof( int ) );

            if ( linesIndex == NULL ) {

                perror( "Error : no such memory" );
                exit(1);

            }

            for ( int i=width; i<newWidth; i++ ) {

                linesIndex[i] = height-1;

            }

            width = newWidth;

            printf( "The grid has now a width of : %d\n", newWidth );
            
        } else {

            int indexColumn = position - 1;
            int indexLine = linesIndex[indexColumn];

            while ( indexLine == -1 ) {

                printf( "The column is full, please choose another : " );
                scanf( "%d", &position );

                indexColumn = position - 1;
                indexLine = linesIndex[indexColumn];

            }

            matrix[indexLine][indexColumn] = player;

            linesIndex[indexColumn]--;

            printf( "\n" );

            int countColumnsFull = 0;

            for ( int i=0; i<width; i++ ) {

                if ( linesIndex[i] != -1 ) break;
                else countColumnsFull++;

            }

            if ( countColumnsFull == width ) {

                printf( "The grid is full.\nEnd of the game, thanks for playing !\n" );
                break;

            }

        }

        printf( "\n" );

        // Render the first line

        printf( "  " );

        for ( int i=0; i<width; i++ ) {

            printf( "%d ", i+1 );

        }

        printf( "\n" );

        // Render the matrix

        for ( int i=0; i<height; i++ ) {

            printf( "%d ", i+1 );

            for ( int j=0; j<width; j++ ) {

                printf( "%c ", matrix[i][j] );

            }

            printf( "\n" );

        }

        if ( player == 'X' ) {

            player = 'O';

        } else {

            player = 'X';

        }

    }

    for ( int i=0; i<height; i++ ) {

        free(matrix[i]);

    }

    free(matrix);
    free(linesIndex);

    return 0;
}