/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:56:27 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/09 17:22:50 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_timer(void *ptr)
{
	t_setup			*setup;
	t_philo			*philo;

	philo = (t_philo *)ptr;
	setup = get_setup();
	pthread_mutex_lock(setup->std_out);
	while (!setup->death && (!setup->max_meals
			|| setup->overflow < setup->num_philos))
	{
		pthread_mutex_unlock(setup->std_out);
		ft_usleep((setup->time_to_die
				- (get_timestamp_in_ms() - philo->last_fed)) * 1000);
		pthread_mutex_lock(setup->std_out);
		if (get_timestamp_in_ms() - philo->last_fed >= setup->time_to_die)
		{
			write_std_out(DEAD, philo->index + 1, get_timestamp_in_ms());
			setup->death += 1;
		}
	}
	pthread_mutex_unlock(setup->std_out);
	return (NULL);
}
