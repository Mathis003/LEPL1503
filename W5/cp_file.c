#include <sys/mman.h>

/*
 * @pre file_name != NULL, name of the original file
 *      new_file_name != NULL, name of the new file (the copy)
 *
 * @post copy the contents of {file_name} to {new_file_name}.
 *       return 0 if the function terminates with success, -1 in case of errors.
 */
int copy(char *file_name, char *new_file_name)
{
    int fd = open(file_name, O_RDWR);
    if (fd == -1) { return -1; }

    struct stat buffer_src;
    if (fstat(fd, &buffer_src) == -1) { return -1; }

    int size_file = buffer_src.st_size;
    mode_t mode_autorisation = buffer_src.st_mode;

    int new_fd = open(new_file_name, O_RDWR | O_CREAT | O_TRUNC, mode_autorisation);
    if (new_fd == -1) { return -1; }

    if (ftruncate(new_fd, size_file) == -1) { return -1; }

    void *mapper_src = mmap(NULL, size_file, PROT_READ, MAP_SHARED, fd, 0);
    if (mapper_src == MAP_FAILED) { return -1; }

    void *mapper_dest = mmap(NULL, size_file, PROT_WRITE, MAP_SHARED, new_fd, 0);
    if (mapper_dest == MAP_FAILED) { munmap(mapper_src, size_file); return -1; }

    memcpy(mapper_dest, mapper_src, size_file);

    if (msync(mapper_dest, size_file, MS_SYNC) == -1)
    {
        munmap(mapper_src, size_file);
        munmap(mapper_dest, size_file);
        return -1;
    }

    if ((munmap(mapper_src, size_file) == -1) | (munmap(mapper_dest, size_file) == -1)) { return -1; }

    if ((close(fd) == -1) | (close(new_fd) == -1)) { return -1; }

    return 0;
}

int main() { return 0; }