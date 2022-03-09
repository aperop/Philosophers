/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:11:20 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/08 14:31:13 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "structures.h"
#include "philo.h"

static void	start_routine(t_philo *philo)
{
	t_setup		*setup;
	pthread_t	tid;

	setup = get_setup();
	pthread_create(&tid, NULL, &death_timer, philo);
	pthread_detach(tid);
	while (!setup->death && (!setup->max_meals
			|| setup->satisfied < setup->num_philos))
	{
		grab_forks(philo);
		eat(philo);
		drop_forks(philo);
		dream(philo);
		think(philo);
	}
	return ;
}

static void	init_philo(t_philo *philo)
{
	pthread_mutex_t	**forks;
	t_setup			*setup;

	setup = get_setup();
	philo->meals = 0;
	philo->last_fed = 0;
	forks = get_forks();
	philo->right_fork = &(*forks)[philo->index];
	if (philo->index == 0)
		philo->left_fork = &(*forks)[setup->num_philos - 1];
	else
		philo->left_fork = &(*forks)[philo->index - 1];
}

static void	*spawn_philo(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	init_philo(philo);
	start_routine(philo);
	return (0);
}

static void	simulate(t_philo *philos)
{
	unsigned long	i;
	t_setup			*setup;

	setup = get_setup();
	i = 0;
	while (i < setup->num_philos)
	{
		philos[i].index = i;
		if (pthread_create(&philos[i].tid, NULL, spawn_philo, &philos[i]) != 0)
			break ;
		i++;
	}
	if (i != setup->num_philos)
	{
		print_message(THREAD);
		setup->death = 1;
	}
	while (i != 0)
	{
		i--;
		pthread_join(philos[i].tid, NULL);
	}
}

void	start_simulation(void)
{
	t_setup			*setup;
	t_philo			*philos;

	setup = get_setup();
	philos = malloc(setup->num_philos * sizeof(t_philo));
	if (philos == NULL)
		return ;
	// print_message(HEAD);
	simulate(philos);
	free(philos);
	// print_message(FOOT);
}
