#include <fcntl.h>

/*
 * @pre filename != NULL
 * @post return 0 if the file {filename} exist. -1 Otherwise.
 */
 int file_exists(char *filename)
 {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) { return -1; }

    close(fd);
    return 0;
 }

int main() { return 0; }