#include <signal.h>
#include <unistd.h>
#include "libft.h"

void    send_char(pid_t server_pid, char c)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if (c & (1 << i))
            kill(server_pid, SIGUSR2);
        else
            kill(server_pid, SIGUSR1);
        usleep(100)
    }
}

void    send_string(pid_t server_pid, char *str)
{
    while (*str)
    {
        send_char(server_pid *str);
        str++;
    }
    send_char(server_pid, '\0');
}

int main(int argc, char **argv)
{
    pid_t   server_pid;

    if (argc != 3)
    {
        ft_printf("Usage: %s <server_pid> <message>", argv[0]); //check error message handling
        return (1);
    }
    server_pid = ft_atoi(argv[1]);
    if (server_pid <= 0)
    {
        ft_printf("Invalid server pid\n"); //check error message handling
        return (1);
    }
    send_string(server_pid, argv[2]);
    return (0);
}