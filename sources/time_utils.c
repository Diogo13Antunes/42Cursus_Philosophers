/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piriquito <piriquito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:41:08 by piriquito         #+#    #+#             */
/*   Updated: 2022/09/09 17:13:14 by piriquito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long int	get_current_time(void)
{
	struct timeval	time;
	unsigned long	current_time;

	if (gettimeofday(&time, NULL) == -1)
		return (0);
	current_time = (time.tv_sec) * 1000 + (time.tv_usec) / 1000;
	return (current_time);
}

int	init_timer(t_philos *philos)
{
	unsigned long	*time;

	time = malloc(sizeof(unsigned long));
	if (!time)
		return (-1);
	*time = get_current_time();
	philos->time = time;
	return (0);
}

void	print_time(t_philos *philos)
{
	unsigned long	current_time;

	current_time = get_current_time() - *philos->time;
	printf("Time [%d] = %ld\n", philos->id, current_time);
}
