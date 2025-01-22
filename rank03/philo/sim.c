/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:11:52 by riamaev           #+#    #+#             */
/*   Updated: 2025/01/12 14:06:52 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_table(t_philosopher *m)
{
	pthread_mutex_lock(m->first_fork);
	if (actual_time() + m->p->time_to_eat <= m->die_time
		&& (m->times_eaten < m->p->eats || m->p->eats == -1))
		eating(m);
	else
	{
		pthread_mutex_unlock(m->first_fork);
		if (actual_time() + m->p->time_to_eat > m->die_time)
			die(m);
		return (0);
	}
	if (actual_time() + m->p->time_to_sleep > m->die_time)
	{
		m->die_time -= m->p->time_to_eat;
		die(m);
		return (0);
	}
	else
		sleeping(m);
	thinking(m);
	return (1);
}

int	check_all_philos_ate(t_simulation *philo_and_thread)
{
	int	i;

	i = 0;
	while (i < philo_and_thread->count)
	{
		if (philo_and_thread->philos[i].times_eaten < \
			philo_and_thread->philos[i].p->eats
			&& philo_and_thread->philos[i].data->is_dead \
			== 0)
			return (0);
		i++;
	}
	return (1);
}

void	philo_join(t_simulation *philo_and_thread)
{
	int	i;

	i = 0;
	while (i < philo_and_thread->count)
	{
		pthread_join(philo_and_thread->threads[i], NULL);
		i++;
	}
	if (check_all_philos_ate(philo_and_thread) && \
		philo_and_thread->philos[0].data->is_dead == 0)
		printf("Each philosopher ate %d times\n", \
		philo_and_thread->philos[0].p->eats);
}

void	philo_create(t_simulation *philo_and_thread)
{
	int	i;

	i = 0;
	while (i < philo_and_thread->count)
	{
		pthread_create(&philo_and_thread->threads[i], \
			NULL, philo_thread, (void *)&philo_and_thread->philos[i]);
		i++;
	}
}

void	*philo_thread(void *philo)
{
	t_philosopher	*m;

	m = (t_philosopher *)philo;
	m->die_time = m->p->start_time + m->p->time_to_die;
	if (m->id % 2 == 0)
		sleep_time(actual_time() + m->p->time_to_eat);
	while (1)
	{
		if (ft_table(m) == 0 || m->data->is_dead == 1)
			return (NULL);
	}
	return (NULL);
}
