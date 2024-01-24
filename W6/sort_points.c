#include <sys/mman.h>

typedef struct points
{
    int NOMA;
    float LEPL1103;
    float LEPL1203;
    float LEPL1108;
    float LEPL1302;
    float LEPL1402;
    float average;
} points_t;

/*
* Function used to compare two structures based on their averages.
*
* @s1 : a pointer to the first structure
* @s2 : a pointer to the second structure
*
* @return an integer less than, equal to, or greater than zero if the first argument is considered to be
*        respectively less than, equal to, or greater than the second
*/
int compar(const void *s1, const void *s2)
{
    points_t *s1_p = (points_t *) s1;
    points_t *s2_p = (points_t *) s2;
    return (s1_p->average - s2_p->average) * 100000000;
}

/*
* Function used to update the file with the structures stored in it
*
* @filename : the path indicating where to find the file (!= NULL)
*
* @return 0 if no error
*        -1 if open failed
*        -2 if mmap failed
*        -3 if munmap failed
*        -4 if msync failed
*        -5 if fstat failed
*        -6 if close failed
*/
int sort(char* filename)
{
    int fd = open(filename, O_RDWR);
    if (fd == -1) { return -1; }

    struct stat buffer;

    if (fstat(fd, &buffer) == -1) { close(fd); return -5; }

    int size_buffer = buffer.st_size;

    points_t *mapper = (points_t *) mmap(NULL, size_buffer, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapper == MAP_FAILED) { close(fd); return -2; }

    for (int i = 0; i < size_buffer / sizeof(points_t); i++) {
        mapper[i].average = (mapper[i].LEPL1103 + mapper[i].LEPL1203 +
                            mapper[i].LEPL1108 + mapper[i].LEPL1302 + mapper[i].LEPL1402) / 5;
    }

    qsort(mapper, size_buffer / sizeof(points_t), sizeof(points_t), &compar);

    if (msync(mapper, size_buffer, MS_SYNC) == -1) { munmap(mapper, size_buffer); return -4; }

    if (close(fd) == -1) { munmap(mapper, size_buffer); return -6; }

    if (munmap(mapper, size_buffer) == -1) { return -3; }

    return 0;
}

int main() { return 0; }