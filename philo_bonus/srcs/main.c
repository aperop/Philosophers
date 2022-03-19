/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:49:52 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/17 16:50:13 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	parse_args(argc, argv);
	set_base_timestamp();
	start_simulation();
	unlink_all_sems();
	exit (0);
}
