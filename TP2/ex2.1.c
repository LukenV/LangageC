#include <stdlib.h>
#include <stdio.h>
#define PHY_SIZE 50

int main(int argc, char const *argv[])
{

    printf( "This script will calculate the average of all student's grades of a class and the deviation from the average for each student\n" );

    printf( "\n" );

    printf( "Enter the grades of the student, Ctrl-D to end :\n" );

    float grades[PHY_SIZE] = {0};

    int logicalSize = 0;

    float grade = 0.0;

    while ( ( logicalSize < PHY_SIZE ) && ( scanf( "%f", &grade ) != EOF ) ) {

        grades[logicalSize] = grade;

        logicalSize++;

    }

    float sum = 0.0;

    for ( int i=0; i<logicalSize; i++ ) {

        sum += grades[i]; 

    }

    float average = (float) sum / logicalSize;

    printf( "Average = %.2f\n", average );

    printf( "\n" );

    printf( "Student deviation from the average :\n" );

    printf( "\n" );

    for ( int i=0; i<logicalSize; i++ ) {

        float deviation = grades[i] - average;

        printf( "   Student's n°%d : %.2f - %.2f = %.2f\n", i+1, grades[i], average, deviation );

    }
    
    return 0;
}