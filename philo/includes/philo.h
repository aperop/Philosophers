/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:36:18 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/10 14:27:58 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include "structs.h"
# include <sys/time.h>
# include <unistd.h>

# define HEAD_MSG		"|    ms    |  id  |                   |\n"
# define FOOT_MSG		"|-------------------------------------|\n"
# define THREAD_MSG		"| Failed to create all threads.       |\n"

/* Death */
void			*death_timer(void *ptr);

/* Forks */
pthread_mutex_t	**get_forks(void);
void			set_forks(void);
void			destroy_forks(void);

/* Check input (writes and exits upon error) */
void			check_args(int argc, char **argv);

/* std_out */
void			write_std_out(int state, unsigned long i,
					unsigned long timestamp);
void			print_message(int option);

/* Routine */
void			grab_forks(t_philo *philo);
void			eat(t_philo *philo);
void			drop_forks(t_philo *philo);
void			dream(t_philo *philo);
void			think(t_philo *philo);

/* Simulation */
void			start_simulation(void);

/* setup */
t_setup			*get_setup(void);
/* Set setup (store input in the globally accessible struct 't_setup *setup') */
void			parse_args(int argc, char **argv);
void			destroy_setup(void);

/* Timestamp */
unsigned long	get_timestamp_in_ms(void);
void			set_base_timestamp(void);

/* Utils */
void			ft_usleep(unsigned long sleep_time);
unsigned long	ft_atoi(char *str);

#endif
