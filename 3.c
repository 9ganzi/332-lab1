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

    char buffer[50];
    char xyz[] = "XYZ";
    int count = -1;

    while (count != 0)
    {
        // read 50 character
        count = read(fd1, buffer, 50);
        // replace 5 with A
        for (int i = 0; i < count; i++)
        {
            if (buffer[i] == '5')
                buffer[i] = 'A';
        }
        // write it to destination.txt
        write(fd2, buffer, count);
        // add xyz only if 50 characters are written to destination.txt
        if (count == 50)
            write(fd2, xyz, 3);
    }

    close(fd1);
    close(fd2);
    return 0;
}