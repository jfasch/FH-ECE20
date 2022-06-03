#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int main(int argc, char** argv)
{
    if (! (argc == 3 || argc == 4)) {
        fprintf(stderr, "%s <filename> <interval>\n", argv[0]);
        return 42;
    }
    
    const char* filename = argv[1];
    const char* interval_str = argv[2];
    int niterations = -1;

    if (argc == 4)
        niterations = atoi(argv[3]);

    int interval = atoi(interval_str);
    unsigned int time_remaining;
    int fd;    
    char buffer[32];
    ssize_t nread;
    ssize_t nwritten;

    int iteration = 0;
    while (niterations == -1 || iteration++ < niterations) {
        fd = open(filename, O_RDONLY);
        if (fd == -1) {
            perror("open");
            return 1;
        }

        nread = read(fd, buffer, sizeof(buffer));
        if (nread == -1) {
            perror("read");
            return 2;
        }

        nwritten = write(STDOUT_FILENO, buffer, nread);
        if (nwritten == -1) {
            perror("write");
            return 2;
        }

        time_remaining = sleep(interval);
        if (time_remaining != 0)
            fprintf(stderr, "did not sleep %d seconds, %d remaining\n", interval, time_remaining);

        int error = close(fd);
        if (error == -1) {
            perror("close");
            return 10;
        }
    }

    return 0;
}
