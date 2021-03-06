/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:03:27 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/04/08 00:03:47 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>
#include <unistd.h>
#include "structs.h"
#include "philo.h"

static void	start_routine(t_philo *philo)
{
	t_setup		*setup;
	pthread_t	tid;

	setup = get_setup();
	pthread_create(&tid, NULL, &death_timer, philo);
	pthread_detach(tid);
	while (1)
	{
		grab_forks(philo);
		eat(philo);
		nap(philo);
		think(philo);
	}
	return ;
}

static void	init_philo(t_philo *philo)
{
	t_setup	*setup;

	setup = get_setup();
	sem_wait(setup->overflow);
	philo->meals = 0;
	philo->last_fed = 0;
}

static void	*spawn_philo(t_philo *philo)
{
	init_philo(philo);
	start_routine(philo);
	exit (0);
}

static void	simulate(t_philo **philos)
{
	unsigned long	i;
	t_setup			*setup;
	t_setup			*setup_p;

	setup = get_setup();
	i = 0;
	while (i < setup->num_philos)
	{
		(*philos)[i].index = i;
		(*philos)[i].pid = fork();
		if ((*philos)[i].pid == 0)
		{
			setup_p = get_setup();
			*setup_p = *setup;
			set_base_timestamp();
			spawn_philo(&(*philos)[i]);
		}
		else if ((*philos)[i].pid == -1)
			break ;
		ft_usleep(10);
		i++;
	}
	end_simulation(philos, i);
}

void	start_simulation(void)
{
	t_setup			*setup;
	t_philo			*philos;

	setup = get_setup();
	philos = malloc(setup->num_philos * sizeof(t_philo));
	if (philos == NULL)
		return ;
	print_message(HEAD);
	simulate(&philos);
	free(philos);
	print_message(FOOT);
}
