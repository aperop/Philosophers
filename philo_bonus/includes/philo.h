/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:01:44 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/17 17:02:11 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include <stdlib.h>
# include <stdio.h>
# include "structs.h"
# include <sys/time.h>
# include <unistd.h>
# include <semaphore.h>

# define HEAD_MSG		"|    ms    |  id  |       state       |\n"
# define FOOT_MSG		"|-------------------------------------|\n"
# define PROCESS_MSG	"| Failed to create all processes.     |\n"

/* Death */
void			*death_timer(void *ptr);

/* Input */
void			check_args(int argc, char **argv);

/* Prompt */
void			write_prompt(t_setup state, unsigned long i,
					unsigned long timestamp);
void			print_message(int option);

/* Routine */
void			eat(t_philo *philo);
void			nap(t_philo *philo);
void			think(t_philo *philo);
void			grab_forks(t_philo *philo);

/* Simulation */
void			launch_simulation(void);
void			end_simulation(t_philo **philos, unsigned long i);

/* setup */
t_setup			*get_setup(void);
void			parse_args(int argc, char **argv);
void			unlink_all_sems(void);

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
