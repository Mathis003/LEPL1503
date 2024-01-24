#include <stdio.h>

/*
The strcat() function appends the src string to the dest string,
overwriting the null byte ('\0') at the end of dest, and then adds a
terminating null byte. The strings may not overlap, and the dest
string must have enough space for the result.
*/
char *strcat(char *dest, const char *src)
{
    int idx = 0;
    while (*(dest + idx) != '\0') { idx++; }

    int i = 0;
    while (*(src + i) != '\0')
    {
        dest[idx] = src[i];
        i++; idx++;
    }
    dest[idx] = src[i];

    return dest;
}

int main()
{
    char dest_buffer1[50] = "Hello : ";
    char dest_buffer2[50] = "Not Hello : ";

    strcat(dest_buffer1, "testing the function");
    strcat(dest_buffer2, "Another text...");

    printf("dest_buffer1 = %s\n", dest_buffer1);  // Hello : testing the function
    printf("dest_buffer1 = %s\n", dest_buffer2);  // Not Hello : Another text...

    return 0;
}