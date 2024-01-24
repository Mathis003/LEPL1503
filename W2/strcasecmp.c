#include <stdio.h>

/*
The strcasecmp() function compares the two strings s1 and s2, ignoring the case of the characters.
It returns an integer less than, equal to, or greater than zero if s1 is found, respectively, to be less than, to match, or be greater than s2.
The strncasecmp() function is similar, except it only compares the first n characters of s1.  
*/
int strcasecmp(const char *s1, const char *s2)
{
    int idx = 0;
    char elem1;
    char elem2;

    while ((*(s1 + idx) != '\0') && (*(s2 + idx) != '\0'))
    {
        elem1 = *(s1 + idx);
        elem2 = *(s2 + idx);
        
        if (65 <= (*(s1 + idx)) && (*(s1 + idx) <= 90)) { elem1 += ('a' - 'A'); }
        if (65 <= (*(s2 + idx)) && (*(s2 + idx) <= 90)) { elem2 += ('a' - 'A'); }
        
        if (elem1 != elem2) { return (elem1 < elem2) ? -1 : 1; }

        idx++;
    }

    if ((*(s1 + idx) == '\0') && (*(s2 + idx) == '\0')) { return 0; }
    if (*(s1 + idx) == '\0')                            { return -1; }
    return 1;
}

int main()
{
    printf("strcasecmp('testing the function', 'testing the FunctioN') = %d\n", strcasecmp("testing the FunctioN", "testing the FunctioN"));  // 0
    printf("strcasecmp('Another text...', 'Another toxt...') = %d\n", strcasecmp("Another text...", "Another toxt..."));                      // -1
    printf("strcasecmp('Another text...', 'Anather text...') = %d\n", strcasecmp("Another text...", "Anather text..."));                      // 1

    return 0;
}