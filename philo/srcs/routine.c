/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:11:18 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/22 16:26:17 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_forks(t_philo *philo)
{
	t_setup			*setup;

	setup = get_setup();
	if (philo->index % 2 == 1)
		ft_usleep(100);
	pthread_mutex_lock(philo->left_fork);
	write_std_out(GRAB, philo->index + 1, get_timestamp_in_ms());
	if (philo->left_fork == philo->right_fork)
	{
		ft_usleep(setup->time_to_die * 1000 + 500);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	write_std_out(GRAB, philo->index + 1, get_timestamp_in_ms());
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
	write_std_out(EAT, philo->index + 1, timestamp);
	if (philo->meals == setup->max_meals)
		setup->overflow++;
	pthread_mutex_unlock(setup->std_out);
	ft_usleep(setup->time_to_eat * 1000);
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
	t_setup			*setup;

	setup = get_setup();
	pthread_mutex_lock(setup->std_out);
	write_std_out(SLEEP, philo->index + 1, get_timestamp_in_ms());
	pthread_mutex_unlock(setup->std_out);
	ft_usleep(setup->time_to_sleep * 1000);
	return ;
}

void	think(t_philo *philo)
{
	t_setup			*setup;

	setup = get_setup();
	pthread_mutex_lock(setup->std_out);
	write_std_out(THINK, philo->index + 1, get_timestamp_in_ms());
	pthread_mutex_unlock(setup->std_out);
	return ;
}
