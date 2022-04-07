/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:03:32 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/04/08 00:03:33 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	kill_processes(t_philo **philos, unsigned long i)
{
	while (i != 0)
	{
		i--;
		kill((*philos)[i].pid, 9);
	}
}

void	end_simulation(t_philo **philos, unsigned long i)
{
	t_setup			*setup;
	pid_t			wait_for_overflow;

	setup = get_setup();
	if (i != setup->num_philos)
	{
		sem_wait(setup->std_out);
		print_message(PROCESS);
		kill_processes(philos, i);
		return ;
	}
	wait_for_overflow = fork();
	if (wait_for_overflow == 0)
	{
		while (i > 0)
		{
			i--;
			sem_wait(setup->overflow);
		}
		exit (0);
	}
	waitpid(-1, 0, 0);
	kill_processes(philos, setup->num_philos);
	kill(wait_for_overflow, 9);
}
