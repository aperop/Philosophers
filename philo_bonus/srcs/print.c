/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:11:16 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/17 17:08:22 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_std_out(int state, unsigned long id, unsigned long timestamp)
{
	t_setup				*setup;
	static const char	*str[] = {
		"| %8ld    %3ld   is thinking.      |\n",
		"| %8ld    %3ld   has taken a fork. |\n",
		"| %8ld    %3ld   is eating.        |\n",
		"| %8ld    %3ld   is sleeping.      |\n",
		"| %8ld    %3ld   died.             |\n"
	};

	setup = get_setup();
	printf(str[state], timestamp, id);
}
/*
		"| %8ld    %3ld   is thinking.      |\n",
		"| %8ld    %3ld   has taken a fork. |\n",
		"| %8ld    %3ld   is eating.        |\n",
		"| %8ld    %3ld   is sleeping.      |\n",
		"| %8ld    %3ld   died.             |\n"
*/

void	print_message(int option)
{
	if (option == NO_MEALS)
	{
		printf("\nPhilosophers don't want to eat!\n\n");
		exit (0);
	}
	else if (option == NO_PHILOS)
	{
		printf("\nNo one and nothing to eat!\n\n");
		exit (0);
	}
	else if (option == HEAD)
	{
		printf(FOOT_MSG);
		printf(HEAD_MSG);
		printf(FOOT_MSG);
	}
	else if (option == FOOT)
		printf(FOOT_MSG);
	else if (option == PROCESS)
		printf(PROCESS_MSG);
	return ;
}
