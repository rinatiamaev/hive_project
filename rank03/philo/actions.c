/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:55:45 by riamaev           #+#    #+#             */
/*   Updated: 2025/01/12 13:56:26 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philosopher *m)
{
	ft_putmsg(m, 0);
	pthread_mutex_lock(m->second_fork);
	ft_putmsg(m, 0);
	ft_putmsg(m, 1);
	if (m->data->is_dead == 1)
	{
		pthread_mutex_unlock(m->second_fork);
		pthread_mutex_unlock(m->first_fork);
		return ;
	}
	m->die_time = actual_time() + m->p->time_to_die + m->p->time_to_eat;
	sleep_time(actual_time() + m->p->time_to_eat);
	if (m->p->eats != -1)
		m->times_eaten += 1;
	pthread_mutex_unlock(m->second_fork);
	pthread_mutex_unlock(m->first_fork);
}

void	sleeping(t_philosopher *m)
{
	ft_putmsg(m, 2);
	sleep_time(actual_time() + m->p->time_to_sleep);
}

void	thinking(t_philosopher *m)
{
	ft_putmsg(m, 3);
}

void	die(t_philosopher *m)
{
	sleep_time(m->die_time);
	ft_putmsg(m, 4);
}
