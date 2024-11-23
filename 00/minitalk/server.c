#include <signal.h>
#include <unistd.h>
#include "libft.h"

static volatile unsigned char   g_char;

g_char = 0;
void    handle_signal(int sig, siginfo_t *info, void *context)
{
    static int  bit_pos = 0;
    (void)context;
    if (sig == SIGUSR2)
        g_char |= (1 << bit_pos);
    bit_pos++;
    if (bit_pos == 8)
    {
        if (g_char == '\0')
        {
            write(1, "\n", 1);
            kill(info->si_pid, SIGUSR1);
        }
        else
            write(1, &g_char, 1);
        g_char = 0;
        bit_pos = 0;
    }
}
int main(void)
{
    pid_t   pid;

    pid = getpid();
    ft_printf("Server PID: %d\n",  pid);
    struct  sigaction sa;
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO | SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    return (0);
}