#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf( "This script will calculation the factorial of an integer typed.\n\n" );

    int n = 0;

    printf( "Please type a positive integer : " );
    scanf( "%d", &n );

    int factorial = 1;

    for ( int i=2; i<=n; i++ ) {

        factorial *= i;

    }

    printf( "\n" );

    printf( "!%d = %d\n", n, factorial );

    return 0;
}

// ex1.3a : Le résultat de 13 est non plausible