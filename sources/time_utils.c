/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:41:08 by piriquito         #+#    #+#             */
/*   Updated: 2022/10/20 16:36:58 by dcandeia         ###   ########.fr       */
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

void	print_time(t_philos *philos)
{
	unsigned long	current_time;

	current_time = get_current_time() - philos->init_time;
	printf("Time [%d] = %ld\n", philos->id, current_time);
}

int	check_time_pass(unsigned long time, unsigned long t_pass)
{
	unsigned long	current_time;

	current_time = get_current_time();
	if (current_time - time >= t_pass)
		return (TRUE);
	else
		return (FALSE);
}
