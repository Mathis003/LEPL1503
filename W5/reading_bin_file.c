#include <sys/mman.h>

/*
 * @pre filename != NULL, name of the file
 * @post returns the sum of all integers stored in the binary file.
 *       return -1 if the file can not be open.
 *       return -2 if the file can not be closed.
 *       return -3 if mmap() fails.
 *       return -4 if munmap() fails.
 *       return -5 if fstat() fails.
 */
int sum_file(char *filename)
{
    int fd = open(filename, O_RDWR);
    if (fd == -1) { return -1; }

    struct stat buf;
    if (fstat(fd, &buf) == -1) { return -5; }

    int size = buf.st_size;
    int nber_integers = size / sizeof(int);

    if (nber_integers == 0) { close(fd); return 0; }

    int *mapper = (int *) mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapper == MAP_FAILED) { return -3; }

    int sum = 0;
    for (int i = 0; i < nber_integers; i++) { sum += mapper[i]; }

    if (close(fd) == -1) { return -2; }

    if (munmap(mapper, size) == -1) { return -4; }

    return sum;
}

int main() { return 0; }