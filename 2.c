#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd1 = open("source.txt", O_RDONLY);
    int fd2 = open("destination.txt", O_WRONLY);

    char *buffer[2];
    while (read(fd1, buffer, 1))
        write(fd2, buffer, 1);
    close(fd1);
    close(fd2);
    return 0;
}