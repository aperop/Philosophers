/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:56:27 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/09 03:38:54 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "philo.h"
#include <unistd.h>
#include <pthread.h>

void	*death_timer(void *ptr)
{
	t_setup			*setup;
	t_philo			*philo;
	unsigned long	timestamp;

	philo = (t_philo *)ptr;
	setup = get_setup();
	pthread_mutex_lock(setup->std_out);
	while (!setup->death && (!setup->max_meals
			|| setup->satisfied < setup->num_philos))
	{
		pthread_mutex_unlock(setup->std_out);
		timestamp = get_timestamp_in_ms();
		better_usleep((setup->time_to_die
				- (timestamp - philo->last_fed)) * 1000);
		timestamp = get_timestamp_in_ms();
		pthread_mutex_lock(setup->std_out);
		if (timestamp - philo->last_fed >= setup->time_to_die)
		{
			write_std_out(deceased, philo->index + 1, get_timestamp_in_ms());
			setup->death += 1;
		}
	}
	pthread_mutex_unlock(setup->std_out);
	return (NULL);
}
