#include <fcntl.h>   // for open
#include <unistd.h>  // for read, write, close
#include <stdio.h>   // for perror

#define BUFFER_SIZE 1024

void    ft_display_file(char *filename)
{
    int     fd;
    char    buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Open the file
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return;
    }

    // Read the file and write the content to the standard output
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        write(1, buffer, bytes_read);
    }

    // Handle read error
    if (bytes_read == -1)
        perror("Error reading file");

    // Close the file
    if (close(fd) == -1)
        perror("Error closing file");
}

int main(int argc, char **argv)
{
    // Check the number of arguments
    if (argc == 1)
    {
        write(2, "File name missing.\n", 19);
        return 1;
    }
    else if (argc > 2)
    {
        write(2, "Too many arguments.\n", 20);
        return 1;
    }

    // Display the file content
    ft_display_file(argv[1]);

    return 0;
}
