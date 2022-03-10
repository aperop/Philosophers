/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:11:28 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/09 17:10:17 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_atoi(char *str)
{
	unsigned long	res;

	res = 0;
	while (*str)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

static unsigned long	time_elapsed(struct timeval *then)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (1000000 * (now.tv_sec - then->tv_sec)
		+ now.tv_usec - then->tv_usec);
}

void	ft_usleep(unsigned long sleep_time)
{
	struct timeval	start;
	t_setup			*setup;

	gettimeofday(&start, NULL);
	setup = get_setup();
	while (!setup->death && time_elapsed(&start) < sleep_time)
		usleep(100);
}
