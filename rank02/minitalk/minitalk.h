/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:19:38 by riamaev           #+#    #+#             */
/*   Updated: 2024/11/24 11:36:14 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

void	ack_handler(int sig);
void	send_char(pid_t server_pid, char c);
void	send_string(pid_t server_pid, char *str);
void	handle_signal(int sig, siginfo_t *info, void *context);

typedef struct s_signal_data
{
	unsigned char	c;
	int				bit_pos;
}		t_signal_data;

#endif
