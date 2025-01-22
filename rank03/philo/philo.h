/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:15:33 by riamaev           #+#    #+#             */
/*   Updated: 2025/01/12 14:09:11 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_simulation_params
{
	int				philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		start_time;
	int				eats;
}	t_simulation_params;

typedef struct s_philosopher
{
	t_simulation_params		*p;
	int						id;
	long long				die_time;
	long long				eat_time;
	pthread_mutex_t			left_fork;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			*first_fork;
	pthread_mutex_t			*second_fork;
	pthread_mutex_t			times_eaten_m;
	pthread_mutex_t			*pr;
	int						times_eaten;
	struct s_simulation		*data;
}	t_philosopher;

typedef struct s_simulation
{
	int				is_dead;
	t_philosopher	*philos;
	pthread_t		*threads;
	int				count;
	pthread_mutex_t	write_msg;
}	t_simulation;

long long		actual_time(void);
void			sleep_time(long long time_in_ms);
int				ft_atoi(const char *str, int *n);
int				check_int(int sign, int *n);
int				ft_atol(const char *str, long long *n);
int				check_ll(int sign, long long *n);

void			init_philos(t_philosopher *philos, \
				t_simulation_params *args, int i);
int				philo_init(t_simulation *philo_and_thread, \
				t_simulation_params *args);
void			ft_putmsg(t_philosopher *m, int print);
void			destroy_and_free(t_simulation *philo_and_thread);
int				ft_table(t_philosopher *m);
void			*philo_thread(void *philo);
void			philo_create(t_simulation *philo_and_thread);
void			philo_join(t_simulation *philo_and_thread);
int				check_all_philos_ate(t_simulation *philo_and_thread);

void			eating(t_philosopher *m);
void			sleeping(t_philosopher *m);
void			thinking(t_philosopher *m);
void			die(t_philosopher *m);

#endif
