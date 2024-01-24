#include <stdio.h>
#include <string.h>

/*
* @return: returns true (1) if str is a palindrome, -1 if str is NULL, otherwise false (0).
*/
int pal(char *str)
{
    if (str == NULL) { return -1; }

    int start = 0;
    int end = strlen(str) - 1;

    while (start <= end)
    {
      
        while (str[start] == ' ') { start++; }
        while (str[end] == ' ')   { end--; }
        
        if (str[start] != str[end]) { return 0; }
        start++; end--;
    }

    return 1;
}

int main()
{
    printf("pal('testing the function') = %d\n", pal("testing the function")); // 0
    printf("pal('Another text...') = %d\n", pal("Another text..."));           // 0
    printf("pal('bob') = %d\n", pal("bob"));                                   // 1

    return 0;
}