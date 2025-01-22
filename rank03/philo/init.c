/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:12:21 by riamaev           #+#    #+#             */
/*   Updated: 2025/01/12 14:03:40 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_philosopher *philos, t_simulation_params *args, int i)
{
	philos->id = i;
	philos->times_eaten = 0;
	philos->p = args;
	pthread_mutex_init(&philos->left_fork, NULL);
	pthread_mutex_init(&philos->times_eaten_m, NULL);
	if (i + 1 == args->philos)
		philos->right_fork = &(philos - i)->left_fork;
	else
		philos->right_fork = &(philos + 1)->left_fork;
	philos->first_fork = &philos->left_fork;
	philos->second_fork = philos->right_fork;
	if (i % 2)
	{
		philos->first_fork = philos->right_fork;
		philos->second_fork = &philos->left_fork;
	}
}

int	philo_init(t_simulation *philo_and_thread, t_simulation_params *args)
{
	int	i;

	philo_and_thread->philos = malloc(sizeof(t_philosopher) * args->philos);
	philo_and_thread->threads = malloc(sizeof(pthread_t) * args->philos);
	philo_and_thread->count = args->philos;
	philo_and_thread->is_dead = 0;
	pthread_mutex_init(&philo_and_thread->write_msg, NULL);
	if (!philo_and_thread->philos || !philo_and_thread->threads)
	{
		destroy_and_free(philo_and_thread);
		return (1);
	}
	i = 0;
	while (i < args->philos)
	{
		philo_and_thread->philos[i].pr = &philo_and_thread->write_msg;
		philo_and_thread->philos[i].data = philo_and_thread;
		init_philos(&philo_and_thread->philos[i], args, i);
		i++;
	}
	return (0);
}

void	ft_putmsg(t_philosopher *m, int print)
{
	const char	*msg[] = {
		"has taken a fork", "is eating", "is sleeping",
		"is thinking", "died"};

	pthread_mutex_lock(m->pr);
	if (m->data->is_dead != 1 && print == 4)
	{
		printf("%lld %d %s\n", actual_time() - m->p->start_time, m->id + 1,
			msg[print]);
		m->data->is_dead = 1;
		pthread_mutex_unlock(m->pr);
		return ;
	}
	else if (m->data->is_dead)
	{
		pthread_mutex_unlock(m->pr);
		return ;
	}
	else
	{
		printf("%lld %d %s\n", actual_time() - m->p->start_time, m->id + 1,
			msg[print]);
		pthread_mutex_unlock(m->pr);
	}
}

void	destroy_and_free(t_simulation *philo_and_thread)
{
	int	i;

	i = 0;
	while (i < philo_and_thread->count)
	{
		pthread_mutex_destroy(&philo_and_thread->philos[i].times_eaten_m);
		pthread_mutex_destroy(&philo_and_thread->philos[i].left_fork);
		i++;
	}
	pthread_mutex_destroy(&philo_and_thread->write_msg);
	free(philo_and_thread->philos);
	free(philo_and_thread->threads);
}
