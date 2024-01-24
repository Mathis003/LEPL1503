#include <stdio.h>

/*
The strlen() function calculates the length of the string pointed
to by s, excluding the terminating null byte ('\0').
*/
size_t strlen(const char *s)
{
    int len = 0;
    while (*(s + len) != '\0') { len++; }
    return len;
}

int main()
{
    printf("strlen('testing the function') = %d\n", strlen("testing the function"));  // 20
    printf("strlen('Another text...') = %d\n", strlen("Another text..."));            // 15

    return 0;
}