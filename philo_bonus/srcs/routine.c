/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1routine.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:25:16 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/18 00:25:17 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_forks(t_philo *philo)
{
	unsigned long	timestamp;
	t_setup			*setup;

	setup = get_setup();
	sem_wait(setup->forks);
	timestamp = get_timestamp_in_ms();
	sem_wait(setup->std_out);
	write_std_out(GRAB, philo->index + 1, timestamp);
	sem_post(setup->std_out);
	if (setup->num_philos == 1)
	{
		ft_usleep(setup->time_to_die * 1000 + 500);
		return ;
	}
	sem_wait(setup->forks);
	timestamp = get_timestamp_in_ms();
	sem_wait(setup->std_out);
	write_std_out(GRAB, philo->index + 1, timestamp);
	sem_post(setup->std_out);
	return ;
}

void	eat(t_philo *philo)
{
	unsigned long	timestamp;
	t_setup			*setup;

	setup = get_setup();
	timestamp = get_timestamp_in_ms();
	sem_wait(setup->std_out);
	philo->last_fed = timestamp;
	philo->meals++;
	write_std_out(EAT, philo->index + 1, timestamp);
	if (philo->meals == setup->max_meals)
		sem_post(setup->overflow);
	sem_post(setup->std_out);
	ft_usleep(setup->time_to_eat * 1000);
	sem_post(setup->forks);
	if (setup->num_philos == 1)
		return ;
	sem_post(setup->forks);
	return ;
}

void	nap(t_philo *philo)
{
	unsigned long	timestamp;
	t_setup			*setup;

	setup = get_setup();
	sem_wait(setup->std_out);
	timestamp = get_timestamp_in_ms();
	write_std_out(SLEEP, philo->index + 1, timestamp);
	sem_post(setup->std_out);
	ft_usleep(setup->time_to_sleep * 1000);
	return ;
}

void	think(t_philo *philo)
{
	unsigned long	timestamp;
	t_setup			*setup;

	setup = get_setup();
	sem_wait(setup->std_out);
	timestamp = get_timestamp_in_ms();
	write_std_out(THINK, philo->index + 1, timestamp);
	sem_post(setup->std_out);
	return ;
}
