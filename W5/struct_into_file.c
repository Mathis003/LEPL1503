#include <sys/mman.h>

typedef struct point
{
    int x;
    int y;
    int z;
} point_t;

/*
 * @pre pt != NULL, pointer to the first point_t in the array
 *      size > 0, the length of the array.
 *      filename != NULL
 * @post writes the array of point_t in the file.
 *       return 0 is everything worked correctly
 *       -1 if open() failed.
 *       -2 if close() failed.
 *       -3 if mmap() failed.
 *       -4 if munmap() failed.
 *       -5 if msync() failed.
 *       -6 if ftruncate() failed.
 *
 */
int save(point_t *pt, int size, char *filename)
{
    int memory_size = size * sizeof(point_t);

    int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR);
    if (fd == -1) { return -1;}

    if (ftruncate(fd, memory_size) == -1) { return -6; }

    void *buffer = mmap(NULL, memory_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (buffer == MAP_FAILED) { return -3; }

    memcpy(buffer, (void *) pt, memory_size);

    if (msync(buffer, memory_size, MS_SYNC) == -1) { return -5; }

    if (close(fd) == -1) { return -2; }

    if (munmap(buffer, memory_size) == -1) { return -4; }

    return 0;
}

int main() { return 0; }