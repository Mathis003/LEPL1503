#include <stdlib.h>

/* Wrapper to the malloc system call.
 * If malloc fails, sleep for 5 seconds, and then try again.
 * If malloc failed 10 times in a row, return NULL.
 */
void *sleepy_malloc(size_t s)
{
    int count = 0;
    void *buf;

    while (count < 10)
    {
        buf = malloc(s);
        if (buf == NULL) { sleep(5); }
        else             { return buf; }
        count++;
    }

    return NULL;
}

int main() { return 0; }