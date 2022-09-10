#include <stdlib.h>
#include <stdio.h>

void main(void)
{
    char array[20];

    array[0] = 8;
    array[1] = 56;
    array[2] = 55;

    while (array[0] != 0)
    {
        array[1] -= 6;
        array[2] -= 6;
        array[0]--;
    }
    
    while (array[1] != 0)
    {
        while (array[2] != 0)
        {
            array[3]++;
            array[4] = 10;
            while (array[4] != 0)
            {
                array[6]++;
                array[4]--;
            }
            
            array[2]--;
        }
        while (array[3] != 0)
        {
            array[2]++;
            array[3]--;
        }
        array[1]--;
    }
    
    array[0] = 8;
    while (array[0] != 0)
    {
        array[4] += 6;
        array[0]--;
    }
    putchar(array[4]);
    putchar(array[6]);

}