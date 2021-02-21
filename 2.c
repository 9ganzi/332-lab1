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

    if ((fd1 == -1) || (fd2 == -1))
    {
        printf("\nopen() failed\n");
        perror("open");
    }

    char buffer[100];
    int count = (read(fd1, buffer, 100));

    // loop until there's no content left to read
    while (count != 0)
    {
        // writing to "destination.txt"
        write(fd2, buffer, count);
        count = (read(fd1, buffer, 100));
    }

    close(fd1);
    close(fd2);
    return 0;
}