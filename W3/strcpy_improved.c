#include <stdlib.h>
#include <string.h>

/*
* Creates a buffer that has the same size as src, and copies the content of src to this buffer.
*
* @src: string to be copied
* @return: return pointer. if src == NULL or in case of error, return NULL
*
* Remember that strings are terminated with '\0' and that strlen("abc") returns 3 even if 4 bytes are required to store this string.
*/
char *buf_strcpy(const char *src)
{
    if (src == NULL) { return NULL; }

    int length_src = strlen(src);

    char *buffer = (char *) malloc((length_src + 1) * sizeof(char));
    if (buffer == NULL) { return NULL; }

    for (int i = 0; i <= length_src; i++) {  buffer[i] = src[i]; }

    return buffer;
}

int main() { return 0; }