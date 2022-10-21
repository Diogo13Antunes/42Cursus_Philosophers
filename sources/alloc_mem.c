/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:42:20 by dcandeia          #+#    #+#             */
/*   Updated: 2022/10/21 12:45:40 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_alloc_memory(t_philos **phi)
{
	pthread_mutex_t	*mutex;
	int				*wait_initialize;
	int				*is_alive;

	is_alive = malloc(sizeof(int));
	wait_initialize = malloc(sizeof(int));
	mutex = malloc(sizeof(pthread_mutex_t));
	if (!is_alive || !wait_initialize || !mutex)
	{
		free_all_pointers(is_alive, wait_initialize, mutex);
		return (0);
	}
	if (pthread_mutex_init(mutex, NULL))
	{
		free_all_pointers(mutex, is_alive, wait_initialize);
		return (0);
	}
	set_alloc_mem(phi, is_alive, wait_initialize, mutex);
	return (1);
}

void	set_alloc_mem(t_philos **phi, int alive, int wait, pthread_mutex_t *m)
{
	
}