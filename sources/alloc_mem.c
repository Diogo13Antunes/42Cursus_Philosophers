/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:42:20 by dcandeia          #+#    #+#             */
/*   Updated: 2022/10/26 11:25:13 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	free_allocated_memory(t_philos *philos)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(philos->main_locker);
	free_all_pointers(philos->init_timer_bool, philos->is_alive,
		philos->main_locker);
	while (++i < philos->data.nbr_philos)
		pthread_mutex_destroy(&philos[i].right.lock);
	free(philos);
	return (0);
}
