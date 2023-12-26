#include <limits.h>
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

        factorial = factorial * i;

    }

    printf( "\n" );

    printf( "INT_MAX = %d\n", INT_MAX );

    printf( "!%d = %d\n", n, factorial );

    return 0;
}

/* ex1.3b : à partir de la valeur de calcul 13, le résultat n'est plus correct
 car le résultat de la factorielle de 12 est 479.001.600, et si on le multiplie
 par 13 pour calculer la factorielle de 13, la valeur du resultat est au-delà
 de la valeur maximale possible d'un entier est 2.147.483.647 */