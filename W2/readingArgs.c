#include <stdio.h>

int main(int argc, char **argv)
{
    for(int i = 1; i < argc; i += 2)
    {
        if (i == 1) { printf("%s", argv[i]); }
        else        { printf(" %s", argv[i]); }
    }

    printf("\n");
    
    return 0;
}