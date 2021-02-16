#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd;
    fd = open("destination.txt", O_RDONLY|O_CREAT);
    if (fd == -1)
    {
        printf("\n open() failed with error [%s]\n", strerror(errno));
        return 1;
    }
    int c = close(fd);
    return 0;
}