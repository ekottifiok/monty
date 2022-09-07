#include <stdio.h>

void print(char **str)
{
    while (*str != NULL)
        puts(*str++);
    
}
void main(void)
{
    char *s;
    s = "Hellodklfdjfkdsjflkdsj;odskfjosd";
    // print(((char **)({"hELL", "FILE"};)));
}