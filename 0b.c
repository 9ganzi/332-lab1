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

    // open file if exist, create file if it doesn't exist
    fd = open("destination.txt", O_RDWR|O_CREAT);
    if (fd == -1)
    {
        printf("\n open() failed\n");
        perror("open");
        return 1;
    }
    close(fd);
    return 0;
}