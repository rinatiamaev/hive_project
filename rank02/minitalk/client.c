/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:24:58 by riamaev           #+#    #+#             */
/*   Updated: 2024/11/24 13:57:15 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
#include "minitalk.h"

static volatile int	g_ack_received = 0;

void	ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	send_char(pid_t server_pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_ack_received = 0;
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		while (!g_ack_received)
			pause();
		i++;
	}
}

void	send_string(pid_t server_pid, char *str)
{
	while (*str)
	{
		send_char(server_pid, *str);
		str++;
	}
	send_char(server_pid, '\0');
}

int	main(int ac, char **av)
{
	pid_t	server_pid;

	if (ac != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", av[0]);
		return (1);
	}
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
	{
		ft_printf("Invalid server PID.\n");
		return (1);
	}
	signal(SIGUSR1, ack_handler);
	send_string(server_pid, av[2]);
	return (0);
}
