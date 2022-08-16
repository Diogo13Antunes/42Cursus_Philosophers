/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogoantunes <diogoantunes@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:24:47 by diogoantune       #+#    #+#             */
/*   Updated: 2022/08/10 14:31:41 by diogoantune      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *philos)
{
	t_philos		phi;
	unsigned int	end_time;

	phi = *(t_philos *)philos;
	pthread_mutex_lock(phi.start);
	// printf("Philo [%d] creado!\n", phi.id);
	// printf("[%d] ", phi.t_life);
	// printf("[%d] ", phi.t_eat);
	// printf("[%d] ", phi.t_sleep);
	// printf("[%d] ", phi.nbr_eats);
	// printf("\n");
	pthread_mutex_unlock(phi.start);
	// sleep(1);
	end_time = get_time();
	printf("Time = %u\n", (end_time - *phi.time_start) / 1000);
	return (NULL);
}
