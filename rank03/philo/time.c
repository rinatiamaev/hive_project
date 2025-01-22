/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 06:45:18 by riamaev           #+#    #+#             */
/*   Updated: 2025/01/12 14:00:34 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	actual_time(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL))
		return (-1);
	return (((long long)t.tv_sec * 1000) + ((long long)t.tv_usec / 1000));
}

void	sleep_time(long long waiting_time)
{
	long long	t;

	t = actual_time();
	while (waiting_time - t > 5)
	{
		usleep(1000 * (waiting_time - t - 5));
		t = actual_time();
	}
	while (waiting_time > t)
		t = actual_time();
}
