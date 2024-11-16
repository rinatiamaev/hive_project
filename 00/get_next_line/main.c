#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return (1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
/*
    printf("Enter text (Ctrl+C to end):\n");
    fd = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
*/
    return (0);
}