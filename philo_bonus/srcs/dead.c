/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:52:46 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/10 16:13:59 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_timer(void *ptr)
{
	t_setup			*setup;
	t_philo			*philo;

	philo = (t_philo *)ptr;
	setup = get_setup();
	sem_wait(setup->prompt);
	while (!setup->death)
	{
		sem_post(setup->prompt);
		better_usleep((setup->time_to_die
				- (get_timestamp_in_ms() - philo->last_fed)) * 1000);
		sem_wait(setup->prompt);
		if (get_timestamp_in_ms() - philo->last_fed >= setup->time_to_die)
		{
			setup->death = 1;
			write_prompt(DEAD, philo->index + 1, get_timestamp_in_ms());
			break ;
		}
	}
	exit (DEATH_CODE);
}
