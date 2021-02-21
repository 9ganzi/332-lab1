#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{

    char *filepath = argv[1];

    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
    {
        printf("\n open() failed\n");
        perror("open");
        return 1;
    }

    char buffer[100];
    int count = read(fd, buffer, 100);
    // loop until there's no content left to read
    while (count != 0)
    {
        // print to terminal
        write(1, buffer, count);
        // write to buffer
        count = read(fd, buffer, 100);
    }


    close(fd);

    return 0;
}