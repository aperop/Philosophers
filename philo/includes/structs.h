/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:10:57 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/09 16:40:15 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>

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
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		tid;
}	t_philo;

typedef struct s_setup
{
	unsigned long	num_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	max_meals;
	unsigned long	overflow;
	int				death;
	pthread_mutex_t	*std_out;
}	t_setup;

#endif