#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf( "This script will calculation the factorial of an integer typed.\n\n" );

    int n = 0;

    printf( "Please type a positive integer : " );
    scanf( "%d", &n );

    double factorial = 1;

    for ( int i=2; i<=n; i++ ) {

        factorial = factorial * i;

    }

    printf( "\n" );

    printf( "!%d = %.0f\n", n, factorial );

    return 0;
}

/* ex1.3c : la valeur maximale possible d'un nombre de type double
 est bien plus élevée que la valeur maximale possible d'un nombre
 de type int, ce qui fait que le programme calcule correctement
 la factorielle de 13 */