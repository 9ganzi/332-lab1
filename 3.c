#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

// (a) Read the next 50 characters from ​source.txt,​ and among characters read, replace each
// character ’5’ with character ‘A’’ and all characters are then written in ​destination.txt
// (b) Write characters "XYZ" into file ​destination.txt
// ​(c) Repeat the previous steps until the end of file ​source.txt​. The last read step may not have 50
// characters.

int main(int argc, char *argv[])
{
    int fd1 = open("source.txt", O_RDONLY);
    int fd2 = open("destination.txt", O_WRONLY);

    char buffer[51];
    char xyz[] = "XYZ";
    int count = 0;
    while ((read(fd1, buffer, 1)))
    {
        if (buffer[0] == '5')
            buffer[0] = 'A';
        write(fd2, buffer, 1);
        count++;
        if (count == 50)
        {
            write(fd2, xyz, 3);
            count = 0;
        }
    }
    close(fd1);
    close(fd2);
    return 0;
}