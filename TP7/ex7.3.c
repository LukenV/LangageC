#include <stdio.h>
#include <stdlib.h>

int* createArray( int );

int main(int argc, char const *argv[])
{
    return 0;
}

/* Create number's powers array
* PRE: n: integer number strictly positive
* RES: return a n+1 size array
* filled with powers of n
*/

int* createArray (int n) {

    int t[n+1];

    t[0] = 1;

    for (int i=1; i<=n; i++) {

        t[i] = t[i-1] * n;

    }

    return (int*)t;

}

/**
 * 
 * DEBUG :
 * 
 * - Variable t is only existing in the function
 * 'createArray()', so it will no longer exist
 * in the function that called it.
 * 
 * - It is NOT possible to create an array with
 * a defined size inside the main. It is mandatory 
 * to use 'malloc()' instead.
 * 
*/