/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:11:24 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/03/10 15:49:45 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

static unsigned long	*get_base_timestamp(void)
{
	static unsigned long	base = 0;

	return (&base);
}

void	set_base_timestamp(void)
{
	struct timeval	base_tv;
	unsigned long	*base;

	gettimeofday(&base_tv, NULL);
	base = get_base_timestamp();
	*base = ((1000000 * base_tv.tv_sec + base_tv.tv_usec) / 1000);
}

unsigned long	get_timestamp_in_ms(void)
{
	unsigned long	*base;
	struct timeval	rel;

	base = get_base_timestamp();
	gettimeofday(&rel, NULL);
	return (((1000000 * rel.tv_sec + rel.tv_usec) / 1000) - *base);
}
