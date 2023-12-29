#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime( int );
int* prime_numbers( int, int* );
bool first_prime_numbers( int**, int );

int main(int argc, char const *argv[])
{

    printf( "Function 'isPrime' :\n" );

    printf( "\n" );

    int number1 = 13;
    bool prime1 = isPrime( number1 );

    printf( "Is %d prime ? %d\n", number1, prime1 );

    printf( "\n" );

    int number2 = 6;
    bool prime2 = isPrime( number2 );

    printf( "Is %d prime ? %d\n", number2, prime2 );

    printf( "\n" );

    int number3 = 2;
    bool prime3 = isPrime( number3 );

    printf( "Is %d prime ? %d\n", number3, prime3 );

    printf( "\n" );

    printf( "Function 'prime_numbers' :\n" );

    printf( "\n" );

    printf( "Please type the max number (must be equals or greater than 2) : " );

    int max = 0;

    scanf( "%d", &max );

    int size = 0;
    int* primeNumbers = prime_numbers( max, &size );

    printf( "\n" );

    if ( primeNumbers == NULL ) {

        printf( "Error : an error occured.\n" );

    } else {

        if ( size == 0 ) {

            printf( "There's no prime numbers below %d\n", max );

        } else {

            for ( int i=0; i<size; i++ ) {

                printf( "Prime number n°%d : %d\n", i+1, primeNumbers[i] );

            }

        }

    }

    free( primeNumbers );

    printf( "\n" );

    printf( "Function 'first_prime_numbers' :\n" );

    printf( "\n" );

    printf( "Please type the count of prime numbers you want (must be greater than 0) : " );

    int maxSize = 0;

    scanf( "%d", &maxSize );

    int* tab;

    bool result = first_prime_numbers( &tab, maxSize );

    if ( result ) {

        for ( int i=0; i<maxSize; i++ ) {

            printf( "Prime number n°%d/%d : %d\n", i+1, maxSize, tab[i] );

        }

    }
    
    free( tab );
    
    return 0;
}

bool isPrime( int n ) {

    for ( int i=2; i<n; i++ ) {

        if ( n % i == 0 ) return false;

    }

    return true;

}

int* prime_numbers( int n, int* size ) {

    if ( n < 2 ) return NULL;

    int* primeNumbers = (int*) malloc( n * sizeof( int ) );

    if ( primeNumbers == NULL ) return NULL;

    int index = 0;

    for ( int i=2; i<n; i++ ) {

        if ( isPrime( i ) ) {

            primeNumbers[index] = i;
            index++;

        }

    }

    *size = index;

    primeNumbers = realloc( primeNumbers, (*size) * sizeof( int ) );

    return primeNumbers;

}

bool first_prime_numbers( int** t, int maxSize ) {

    if ( maxSize <= 0 ) {

        printf( "Error : the maxSize is too small (<=0).\n" );
        return false;

    }

    int n = 2;
    int currentSize;

    // Array containing the prime numbers

    int* primeNumbers = prime_numbers( n, &currentSize );

    while ( currentSize < maxSize ) {

        n *= 2;

        free( primeNumbers );

        primeNumbers = prime_numbers( n, &currentSize );

    }

    *t = primeNumbers;

    return true;

}