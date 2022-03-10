/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:11:22 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/09 16:40:28 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_setup	*get_setup(void)
{
	static t_setup	setup;

	return (&setup);
}

void	parse_args(int argc, char **argv)
{
	t_setup	*setup;

	setup = get_setup();
	setup->death = 0;
	setup->overflow = 0;
	setup->num_philos = ft_atoi(argv[1]);
	if (setup->num_philos == 0)
		print_message(NO_PHILOS);
	setup->time_to_die = ft_atoi(argv[2]);
	setup->time_to_eat = ft_atoi(argv[3]);
	setup->time_to_sleep = ft_atoi(argv[4]);
	setup->max_meals = 0;
	if (argc == 6)
		setup->max_meals = ft_atoi(argv[5]);
	if (argc == 6 && setup->max_meals == 0)
		print_message(NO_MEALS);
	setup->std_out = malloc(sizeof(pthread_mutex_t));
	if (setup->std_out == NULL)
		exit (1);
	pthread_mutex_init(setup->std_out, NULL);
}

void	destroy_setup(void)
{
	t_setup	*setup;

	setup = get_setup();
	pthread_mutex_destroy(setup->std_out);
	free(setup->std_out);
}
