/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:07:06 by riamaev           #+#    #+#             */
/*   Updated: 2024/11/24 11:39:22 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
#include "minitalk.h"

static volatile t_signal_data	g_signal_data = {0, 0};

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR2)
		g_signal_data.c |= (1 << g_signal_data.bit_pos);
	g_signal_data.bit_pos++;
	if (g_signal_data.bit_pos == 8)
	{
		if (g_signal_data.c == '\0')
			write(1, "\n", 1);
		else
			write(1, (const void *)&g_signal_data.c, 1);
		g_signal_data.c = 0;
		g_signal_data.bit_pos = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
