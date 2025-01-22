/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:31:33 by riamaev           #+#    #+#             */
/*   Updated: 2025/01/12 14:03:10 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_arg(void)
{
	printf("<Usage:> ./philo [Num.Philos][TimeToDie]");
	printf("[TimeToEat][timeToSleep][HowManyMeals]\n");
}

int	save_variables(int argc, char **argv, t_simulation_params *args)
{
	args->eats = -1;
	if (argc != 6 && argc != 5)
		return (1);
	if (ft_atoi(argv[1], &args->philos))
		return (1);
	if (args->philos < 1 || args->philos > 200)
	{
		printf("Please use number philosophers in range 1 to 200\n");
		return (1);
	}
	if (ft_atol(argv[2], &args->time_to_die) || ft_atol(argv[3], \
		&args->time_to_eat)
		|| ft_atol(argv[4], &args->time_to_sleep))
		return (1);
	if (argc == 6)
	{
		if (ft_atoi(argv[5], &args->eats))
			return (1);
	}
	if (args->philos == 0 || args->eats == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_simulation_params	args;
	t_simulation		philo_and_thread;

	if (save_variables(argc, argv, &args))
	{
		check_arg();
		return (0);
	}
	args.start_time = actual_time();
	if (philo_init(&philo_and_thread, &args))
		return (1);
	if (args.philos == 1)
	{
		ft_putmsg(philo_and_thread.philos, 0);
		sleep_time(args.start_time + args.time_to_die);
		printf("%lld %d died\n", actual_time() - args.start_time, 1);
		destroy_and_free(&philo_and_thread);
		return (0);
	}
	philo_create(&philo_and_thread);
	philo_join(&philo_and_thread);
	destroy_and_free(&philo_and_thread);
	return (0);
}
