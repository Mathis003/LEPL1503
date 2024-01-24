#include <sys/mman.h>

/*
 * @pre filename != NULL, index >= 0
 * @post return the integer at the index {index}
 *       of the array in the file {filename}.
 *       return -1 in case of error.
 *       return -2 if index >= length of array.
 */
int get(char *filename, int index)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1) { return -1; }

    struct stat buf;
    int result_fstat = fstat(fd, &buf);
    if (result_fstat == -1) { return -1; }

    int nberElement = buf.st_size/sizeof(int);
    if (nberElement <= index) { close(fd); return -2; }

    int *mapper = mmap(NULL, buf.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (mapper == MAP_FAILED) { close(fd); return -1; }

    int elem = mapper[index];

    if (msync(mapper, buf.st_size, MS_SYNC) == -1)
    {
        munmap((void *) mapper, buf.st_size);
        close(fd);
        return -1;
    }

    if (close(fd) == -1) { munmap((void *) mapper, buf.st_size); return -1; }

    int result_unmap = munmap((void *) mapper, buf.st_size);
    if (result_unmap == -1) { return -1; }

    return elem;   
}

/*
 * @pre filename != NULL, index >= 0
 * @post set the element in the file {filename}
 *       at index {index} at value {value}.
 *       do nothing in case of errors
 */
void set(char *filename, int index, int value)
{
    int fd = open(filename, O_RDWR);
    if (fd == -1) { return; }

    struct stat buf;
    int resultfstat = fstat(fd, &buf);
    if (resultfstat == -1) {  close(fd); return; }

    if (buf.st_size/sizeof(int) <= index) { close(fd); return; }

    int *mapper = mmap(NULL, buf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapper == MAP_FAILED) { close(fd); return; }

    mapper[index] = value;

    if (msync(mapper, buf.st_size, MS_SYNC) == -1)
    {
        munmap((void *) mapper, buf.st_size);
        close(fd);
        return;
    }

    close(fd);
    munmap((void *) mapper, buf.st_size);
}

int main() { return 0; }