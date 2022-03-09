/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:11:12 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/07 17:53:12 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	input_error(const char *str)
{
	printf("\n\e[1;31m%s\n\e[0m", str);
	printf("\e[0;32mUse ./philo number_of_philosophers time_to_die time_to_eat \
time_to_sleep [number_of_times_each_philosopher_must_eat]\n\n\e[0m");
	printf("\e[0;35mnumber_of_philosophers\n\t\e[0m");
	printf("Number of philosophers and forks\n");
	printf("\e[0;35mtime_to_die (in milliseconds)\n\t\e[0m");
	printf("if a philosopher doesn't start eating 'time_to_eat' milliseconds \
after starting his last meal or the beginning of the stimulation, it dies\n");
	printf("\e[0;35mtime_to_eat (in milliseconds)\n\t\e[0m");
	printf("the time it takes for a philosopher to philo_eat. \
During that time he will need to keep the two forks\n");
	printf("\e[0;35mtime_to_sleep (in milliseconds)\n\t\e[0m");
	printf("the time the philosopher will spend sleeping\n");
	printf("\e[0;35mnumber_of_times_each_philosopher_must_eat \
(optional)\n\t\e[0m");
	printf("If all philosophers philo_eat at least this amount of times, \
the stimulation will stop\n\t");
	printf("If not specified, the stimulation will stop only at the death \
of a philosopher\n");
	printf("\e[0;36mPlease provide four or five arguments.\n\e[0m");
	printf("\e[0;36mAll arguments should be positive numbers.\n\e[0m");
	exit(1);
}

void	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 5 && argc != 6)
		input_error("Error: wrong argument.");
	i = 1;
	while (i != argc)
	{
		j = 0;
		if (argv[i][0] == '\0' && i != 5)
			input_error("Error: wrong argument.");
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				input_error("Error: wrong argument.");
			j++;
		}
		i++;
	}
}
