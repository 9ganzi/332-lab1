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
        printf("\n open() failed with error [%s]\n", strerror(errno));
        return 1;
    }

    char buffer[2];
    while (read(fd, buffer, 1) != 0)
        printf("%s", buffer);

    close(fd);

    return 0;
}