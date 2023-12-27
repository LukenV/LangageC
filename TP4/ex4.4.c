#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int choice = 1;
    int height = 0;
    int width = 0;
    int bitDepth = 0;
    int** image;

    while ( choice <= 7 && choice >= 1 ) {

        printf( "\n" );

        printf( "1) Creation of an image with user-defined dimensions and random pixel values\n" );
        printf( "2) Creation of an image with user-defined dimensions and predefined pixel values\n" );
        printf( "3) Display the image\n" );
        printf( "4) Change image size\n" );
        printf( "5) Display image histogram\n" );
        printf( "6) Delete image\n" );
        printf( "7) Quit program\n" );

        printf( "\n" );

        printf( "Type your choice : " );

        scanf( "%d", &choice );

        printf( "\n" );

        switch( choice ) {

            case 1 : {

                if ( width != 0 || height != 0 ) {

                    printf( "Error : there's already an image, it's not possible to create another.\nDelete it before.\n" );
                    break;

                }

                printf( "Type the dimensions of the image (number of lines and then of columns) : " );

                scanf( "%d %d", &height, &width );

                printf( "\n" );

                image = (int**) malloc( height * sizeof( int* ) );

                if ( image == NULL ) {

                    perror( "Error : no such memory\n" );
                    exit(1);

                }

                printf( "Type image bit depth : " );

                scanf( "%d", &bitDepth );

                for ( int i=0; i<height; i++ ) {

                    image[i] = (int*) malloc( width * sizeof( int ) );

                    if ( image[i] == NULL ) {

                        perror( "Error : no such memory\n" );
                        exit(1);

                    }

                    int min = 0;
                    int max = (int) pow( 2, bitDepth );

                    for ( int j=0; j<width; j++ ) {

                        int randomValue = (int) min + ( rand() / ( RAND_MAX + 1.0 ) * max );

                        image[i][j] = randomValue;

                    }

                }

                printf( "\n" );

                printf( "Creation of an image (%d, %d) with bits depth %d with random pixel values\n", height, width, bitDepth );

                break;

            }
            case 2 : {

                if ( width != 0 || height != 0 ) {

                    printf( "Error : there's already an image, it's not possible to create another.\nDelete it before.\n" );
                    break;

                }

                printf( "Type the dimensions of the image (number of lines and then of columns) : " );

                scanf( "%d %d", &height, &width );

                printf( "\n" );

                image = (int**) malloc( height * sizeof( int* ) );

                if ( image == NULL ) {

                    perror( "Error : no such memory\n" );
                    exit(1);

                }

                int max = 0;

                while ( height > max ) {

                    printf( "Type image bit depth : " );

                    scanf( "%d", &bitDepth );

                    max = (int) pow( 2, bitDepth );

                    if ( max != 0 && height > max ) {

                        printf( "\n" );

                        printf( "The bit depth is too small for this size of image.\n" );

                    } 

                    printf( "\n" );

                }

                for ( int i=0; i<height; i++ ) {

                    image[i] = (int*) malloc( width * sizeof( int ) );

                    if ( image[i] == NULL ) {

                        perror( "Error : no such memory\n" );
                        exit(1);

                    }

                    for ( int j=0; j<width; j++ ) {

                        int value = i + 1;

                        image[i][j] = value;

                    }

                }

                printf( "\n" );

                printf( "Creation of an image (%d, %d) with bits depth %d with random pixel values\n", height, width, bitDepth );

                break;

            }
            case 3 : {

                if ( width == 0 && height == 0 ) {

                    printf( "Error : there's no image, it's not possible to display it !\n" );
                    break;

                }

                printf( "Display of the image :\n" );

                printf( "\n" );

                int** lineWalker;

                for ( lineWalker = image; (lineWalker - image) < height; lineWalker++ ) {

                    int* columnWalker;

                    for ( columnWalker  = (*lineWalker); (columnWalker - ( *lineWalker ) ) < width; columnWalker++ ) {

                        printf( "\t%d ", *columnWalker );

                    }

                    printf( "\n" );

                }
                break;
                
            }
            case 4 : {

                if ( width == 0 && height == 0 ) {

                    printf( "Error : there's no image, it's not possible to resize it !\n" );
                    break;

                }

                int newHeight = 0;
                int newWidth = 0;

                printf( "Type the new dimensions of the image (number of lines and then of columns) : " );

                scanf( "%d %d", &newHeight, &newWidth );

                if ( ( newHeight > height && newWidth < width ) || ( newHeight < height && newWidth > width ) ) {

                    printf( "Error : it's not possible to resize by upscaling a dimension and downscaling another dimension.\n" );
                    break;

                }

                if ( newHeight == height && newWidth == width ) {

                    printf( "Error : you don't want to change the dimensions, so I didn't.\n" );
                    break;

                }

                printf( "\n" );

                // Upscaling the image

                if ( newHeight > height || newWidth > width ) {

                    image = (int**) realloc( image, newHeight * sizeof( int* ) );

                    if ( image == NULL ) {

                        perror( "Error : no such memory" );
                        exit(1);

                    }

                    for ( int i=0; i<newHeight; i++ ) {

                        if ( i >= height ) {

                            image[i] = (int*) malloc( newWidth * sizeof( int ) );

                        } else {

                            image[i] = (int*) realloc( image[i], newWidth * sizeof( int ) );

                        }

                        if ( image[i] == NULL ) {

                            perror( "Error : no such memory" );
                            exit(1);
                            
                        }

                    }

                    printf( "The image was successfuly upscaled.\n" );

                }

                // Downscaling the image

                else if ( newHeight < height || newWidth < width ) {

                    for ( int i=0; i<newHeight; i++ ) {

                        if ( i >= height ) {

                            free(image[i]);

                        } else {

                            image[i] = (int*) realloc( image[i], newWidth * sizeof( int ) );

                            if ( image[i] == NULL ) {

                                perror( "Error : no such memory" );
                                exit(1);
                                
                            }

                        }

                    }

                    image = (int**) realloc( image, newHeight * sizeof( int* ) );

                    if ( image == NULL ) {

                        perror( "Error : no such memory" );
                        exit(1);
                        
                    }

                    printf( "The image was successfuly downscaled.\n" );

                }

                height = newHeight;
                width = newWidth;

                break;
                
            }
            case 5 : {

                if ( width == 0 && height == 0 ) {

                    printf( "Error : there's no image, it's not possible to resize it !\n" );
                    break;

                }

                int maxValue = (int) pow( 2, bitDepth );

                // The index will be the value, and the value at the index
                // will be the frequency of the number

                int* histogram = (int*) malloc( maxValue * sizeof( int ) );

                if ( histogram == NULL ) {

                    perror( "Error : no such memory\n" );
                    exit(1);

                }

                for ( int i=0; i<maxValue; i++ ) {

                    histogram[i] = 0;

                }

                // Fill the histogram

                for ( int i=0; i<height; i++ ) {

                    for ( int j=0; j<width; j++ ) {

                        int value = image[i][j];

                        histogram[value]++;

                    }

                }

                int value;
                int frequency;

                for ( int i=0; i<maxValue; i++ ) {

                    value = i;
                    frequency = histogram[value];

                    if ( frequency != 0 ) {

                        printf( "#pixels with value %d : %d\n", value, frequency );

                    }

                }

                printf( "\n" );

                printf( "Count of pixels in the image : %d\n", (height*width) );

                free(histogram);

                break;
                
            }
            case 6 : {

                if ( width == 0 && height == 0 ) {

                    printf( "Error : there's no image, it's not possible to resize it !\n" );
                    break;

                }

                for ( int i=0; i<height; i++ ) {

                    free(image[i]);

                }

                free(image);

                printf( "Image with size (%d, %d) and bitDepth %d deleted.\n", height, width, bitDepth );

                height = 0;
                width = 0;
                bitDepth = 0;

                break;
                
            }
            case 7 : {

                printf( "Left the program successfuly.\n" );

                printf( "\n" );

                if ( height == 0 && width == 0 ) {

                    printf( "No image to free.\n" );

                } else {

                    for ( int i=0; i<height; i++ ) {

                        free(image[i]);

                    }

                    free(image);

                    printf( "Image with size (%d, %d) and bitDepth %d freed.\n", height, width, bitDepth );

                }

                exit(0);
                
            }

        }

    }

    printf( "A wrong number was typed.\nEnd of the program.\n" );

    for ( int i=0; i<height; i++ ) {

        free(image[i]);

    }

    free(image);

    return 0;
}