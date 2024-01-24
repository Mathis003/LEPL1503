#include <stdlib.h>

void *calloc2(size_t nmemb, size_t size)
{
    int total_size = nmemb * size;
    if (total_size == 0) { return NULL; }

    char *buf = (char *) malloc(total_size);
    if (buf == NULL) { return NULL; }

    for (int i = 0; i < total_size; i++) { buf[i] = 0; }

    return buf;
}

int main() { return 0; }