/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:11:09 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/09 14:30:15 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	**get_forks(void)
{
	static pthread_mutex_t	*forks = 0;

	return (&forks);
}

void	set_forks(void)
{
	pthread_mutex_t	**forks;
	t_setup			*setup;
	unsigned long	i;

	forks = get_forks();
	setup = get_setup();
	*forks = (pthread_mutex_t *)malloc(setup->num_philos
			* sizeof(pthread_mutex_t));
	if (*forks == NULL)
	{
		destroy_setup();
		exit (1);
	}
	i = 0;
	while (i < setup->num_philos)
	{
		pthread_mutex_init(&(*forks)[i], NULL);
		i++;
	}
}

void	destroy_forks(void)
{
	pthread_mutex_t	**forks;
	t_setup			*setup;
	unsigned long	i;

	forks = get_forks();
	setup = get_setup();
	i = 0;
	while (i < setup->num_philos)
	{
		pthread_mutex_destroy(&(*forks)[i]);
		i++;
	}
	free(*forks);
}
