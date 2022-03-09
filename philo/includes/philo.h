/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:36:18 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/08 14:12:26 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PROTO_H
# define PROTO_H

# include <stdlib.h>
# include <stdio.h>
# include "structures.h"
# include <sys/time.h>
# include <unistd.h>

# define HEAD_MSG		"|    ms    |  id  |                   |\n"
# define FOOT_MSG		"|-------------------------------------|\n"
# define THREAD_MSG		"| Failed to create all threads.       |\n"

# define THREAD 0
# define HEAD 1
# define FOOT 2
# define NO_MEALS 3
# define NO_PHILOS 4

# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"
# define RESET "\e[0m"

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
void			eat(t_philo *philo);
void			dream(t_philo *philo);
void			think(t_philo *philo);
void			grab_forks(t_philo *philo);
void			drop_forks(t_philo *philo);

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
void			better_usleep(unsigned long sleep_time);
unsigned long	ft_atoi(char *str);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strdup(const char *s, size_t size);
void			nbr_to_string(char *str, unsigned long pos,
					unsigned long nbr, char src);

#endif
