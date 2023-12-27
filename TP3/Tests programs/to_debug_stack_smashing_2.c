#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **args)
{
    int x = 1;
    int y= 2;
    double *t;
    int t2[10];
    int z = 5;
    int zz = 6;

    t = (double *)t2;
    
    
    for (int i=0; i<10; i++){
        t[i] = i;
    }

    printf("x = %d, y= %d, z = %d, zz = %d; t[2] = %lf", x, y, z, zz, t[2]);

    // Trying to convert an array of integers into an array of doubles
    // the problem here is that this is different data type and they
    // don't take the same space in the memory

}