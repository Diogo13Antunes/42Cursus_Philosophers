/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piriquito <piriquito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:24:47 by diogoantune       #+#    #+#             */
/*   Updated: 2022/09/20 10:58:03 by piriquito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	wait_to_init(t_philos *philos)
{
	int				nbr_philos;
	pthread_mutex_t	lock;

	nbr_philos = philos->nbr_philos;
	pthread_mutex_init(&lock, NULL);
	while (*philos->start_locker == 2)
	{
		if (philos->id == nbr_philos)
		{
			pthread_mutex_lock(&lock);
			*philos->start_locker = 1;
			pthread_mutex_unlock(&lock);
		}
	}
}

void	*routine(void *philos)
{
	t_philos		*phi;

	phi = (t_philos *)philos;
	wait_to_init(phi);
	init_timer(phi);
	return (NULL);
}
