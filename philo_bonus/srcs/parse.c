/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1parse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:17:21 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/18 00:18:27 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_setup	*get_setup(void)
{
	static t_setup	setup;

	return (&setup);
}

static void	open_all_sems(void)
{
	t_setup	*setup;
	int		error;

	setup = get_setup();
	error = 0;
	setup->forks = sem_open("forks", \
	O_CREAT | O_EXCL, S_IRWXU, setup->num_philos);
	if (setup->forks == SEM_FAILED)
		error = 1;
	if (!error)
		setup->std_out = sem_open("std_out", \
	O_CREAT | O_EXCL, S_IRWXU, 1);
	if (setup->std_out == SEM_FAILED)
		error = 1;
	if (!error)
		setup->overflow = sem_open("overflow", \
	O_CREAT | O_EXCL, S_IRWXU, setup->num_philos);
	if (setup->overflow == SEM_FAILED)
		error = 1;
	if (!error)
		return ;
	unlink_all_sems();
	write(1, "Failed to initialize semaphores.\n", 33);
	exit (0);
}

void	parse_args(int argc, char **argv)
{
	t_setup	*setup;

	setup = get_setup();
	setup->death = 0;
	setup->num_philos = ft_atoi(argv[1]);
	if (setup->num_philos == 0)
		print_message(NO_PHILOS);
	setup->time_to_die = ft_atoi(argv[2]);
	setup->time_to_eat = ft_atoi(argv[3]);
	setup->time_to_sleep = ft_atoi(argv[4]);
	setup->max_meals = 0;
	if (argc == 6)
		setup->max_meals = ft_atoi(argv[5]);
	if (argc == 6 && setup->max_meals == 0 && argv[5][0] == '0')
		print_message(NO_MEALS);
	unlink_all_sems();
	open_all_sems();
}

void	unlink_all_sems(void)
{
	sem_unlink("std_out");
	sem_unlink("forks");
	sem_unlink("overflow");
}
