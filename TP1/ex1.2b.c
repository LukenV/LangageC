#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf( "This script will make the multiplication of the two floats typed.\n" );

    float float1;
    float float2;

    printf( "Enter the first float : " );
    scanf( "%f", &float1 );

    printf( "Enter the second float : " );
    scanf( "%f", &float2 );

    float multiplication = float1 * float2;

    printf( "%f * %f = %f\n", float1, float2, multiplication );

    return 0;
}