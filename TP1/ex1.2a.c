#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf( "This script will make the multiplication of the two integers typed.\n" );

    int integer1;
    int integer2;

    printf( "Enter the first integer : " );
    scanf( "%d", &integer1 );

    printf( "Enter the second integer : " );
    scanf( "%d", &integer2 );

    int multiplication = integer1 * integer2;

    printf( "%d * %d = %d\n", integer1, integer2, multiplication );

    return 0;
}