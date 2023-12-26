#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf( "This script will swap the values of two integers typed.\n" );

    int integer1;
    int integer2;

    printf( "Enter the first integer : " );
    scanf( "%d", &integer1 );

    printf( "Enter the second integer : " );
    scanf( "%d", &integer2 );

    printf();

    printf( "Value of first integer before swap : %d\n", integer1 );
    printf( "Value of second integer before swap : %d\n", integer2 );

    printf();

    int temp = integer1;
    integer1 = integer2;
    integer2 = temp;

    printf( "Value of first integer after swap : %d\n", integer1 );
    printf( "Value of second integer after swap : %d\n", integer2 );

    return 0;
}