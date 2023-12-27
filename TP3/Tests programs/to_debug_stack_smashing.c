#include <stdio.h>

int main(int argc, char **args)
{
    int x = 1;
    int y= 2;
    int t[2] = {3, 4};
    int z = 5;
    int zz = 6;

    t[3] = 100;
    printf("x = %d, y= %d, z = %d, zz = %d; t[2] = %d", x, y, z, zz, t[2]);

    // Trying to set a value out of the array, at index 3 but the
    // indexes available are 0 and 1

}