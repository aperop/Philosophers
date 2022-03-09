/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:10:51 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/08 14:28:42 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	parse_args(argc, argv);
	set_forks();
	set_base_timestamp();
	start_simulation();
	destroy_forks();
	destroy_setup();
	exit (0);
}
