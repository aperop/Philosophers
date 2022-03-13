/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:00:21 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/10 16:00:22 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <semaphore.h>

enum	e_status
{
	THINK,
	GRAB,
	EAT,
	SLEEP,
	DEAD
};

enum	e_print
{
	THREAD,
	HEAD,
	FOOT,
	NO_MEALS,
	NO_PHILOS
};

typedef struct s_philo
{
	int				index;
	unsigned long	last_fed;
	unsigned long	meals;
	pid_t			pid;
}	t_philo;

typedef struct s_setup
{
	unsigned long	num_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	max_meals;
	int				death;
	sem_t			*overflow;
	sem_t			*forks;
	sem_t			*std_out;
}	t_setup;

#endif