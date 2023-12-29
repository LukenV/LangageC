#include <stdio.h>
#include <stdlib.h>

/**
 * PRE : pathFile the full path of a file
 *       array an empty array of integers
 *       logicalSize the logical size of the array
 *       physicalSize the physical size of the array
 * POST : the array is filled with integers which are the lines converted into
 *        integers, the logicalSize and physicalSize are updated.
 * RES : return true if array is filled and, logicalSize and physicalSize
 *       are updated, or else return false.
*/
bool fillArray( char* pathFile, int** array, int* logicalSize, int* physicalSize );

/**
 * PRE : pathFile the full path of a file
 *       array an empty array of strings
 *       logicalSize the logical size of the array
 *       physicalSize the physical size of the array
 * POST : the array is filled with the words of the file,
 *        the logicalSize and physicalSize are updated.
 * RES : return true if array is filled and, logicalSize and physicalSize
 *       are updated, or else return false.
*/
bool countFileWords( char* pathFile, char** array, int* logicalSize, int* physicalSize );

/**
 * PRE : string is a table of char not empty
 *       array an empty array of char
 *       logicalSize the logical size of the array
 *       physicalSize the physical size of the array
 * POST : the array is filled with integers which are the lines converted into
 *        integers, the logicalSize and physicalSize are updated.
 * RES : the logical size of the array, or -1 if an
 *       error occured.
*/
int countStringWords( char* string, char*** array, int* physicalSize );



int main(int argc, char const *argv[])
{
    
    return 0;
}