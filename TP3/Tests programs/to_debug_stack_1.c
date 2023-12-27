#include <stdio.h>

int main(int argc, char **args)
{
    int x = 1;
    int y= 2;
    int t[2] = {3,4};
    int z = 5;
    int zz = 6;

    printf("x = %d, y= %d, z = %d, zz = %d; t[2] = %d", x, y, z, zz, t[2]);

    // Trying to get the value of the third (index 2) element of the table t
    // but there is only two elements, index 2 is out of the array

}