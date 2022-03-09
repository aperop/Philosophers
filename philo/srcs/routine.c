/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:11:18 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/09 05:58:04 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "philo.h"
#include <unistd.h>

void	grab_forks(t_philo *philo)
{
	unsigned long	timestamp;
	t_setup			*setup;

	setup = get_setup();
	if (philo->index % 2 == 1)
		better_usleep(50);
	pthread_mutex_lock(philo->left_fork);
	timestamp = get_timestamp_in_ms();
	write_std_out(grabbing_forks, philo->index + 1, timestamp);
	if (philo->left_fork == philo->right_fork)
	{
		better_usleep(setup->time_to_die * 1000 + 500);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	timestamp = get_timestamp_in_ms();
	write_std_out(grabbing_forks, philo->index + 1, timestamp);
	return ;
}

void	eat(t_philo *philo)
{
	unsigned long	timestamp;
	t_setup			*setup;

	setup = get_setup();
	timestamp = get_timestamp_in_ms();
	pthread_mutex_lock(setup->std_out);
	philo->last_fed = timestamp;
	philo->meals++;
	write_std_out(eating, philo->index + 1, timestamp);
	if (philo->meals == setup->max_meals)
		setup->satisfied++;
	pthread_mutex_unlock(setup->std_out);
	better_usleep(setup->time_to_eat * 1000);
	return ;
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	if (philo->left_fork == philo->right_fork)
		return ;
	pthread_mutex_unlock(philo->left_fork);
	return ;
}

void	dream(t_philo *philo)
{
	unsigned long	timestamp;
	t_setup			*setup;

	setup = get_setup();
	pthread_mutex_lock(setup->std_out);
	timestamp = get_timestamp_in_ms();
	write_std_out(sleeping, philo->index + 1, timestamp);
	pthread_mutex_unlock(setup->std_out);
	better_usleep(setup->time_to_sleep * 1000);
	return ;
}

void	think(t_philo *philo)
{
	unsigned long	timestamp;
	t_setup			*setup;

	setup = get_setup();
	pthread_mutex_lock(setup->std_out);
	timestamp = get_timestamp_in_ms();
	write_std_out(thinking, philo->index + 1, timestamp);
	pthread_mutex_unlock(setup->std_out);
	return ;
}
