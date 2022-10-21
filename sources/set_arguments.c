/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:13:14 by dcandeia          #+#    #+#             */
/*   Updated: 2022/10/21 12:47:58 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	set_alloc_mem(t_philos **phi, int alive, int wait, pthread_mutex_t *m)
{
	
}

void	set_data(t_data *data, char **args)
{
	data->nbr_philos = ft_atoi(args[1]);
	data->t_life = ft_atoi(args[2]);
	data->t_eat = ft_atoi(args[3]);
	data->t_sleep = ft_atoi(args[4]);
	if (args[5])
		data->nbr_eats = ft_atoi(args[5]);
	else
		data->nbr_eats = -1;
	data->nbr_forks = 0;
}

t_philos	*init_data(t_philos *philos, t_data data)
{
	int				i;

	i = -1;
	while (++i < data.nbr_philos)
	{
		philos[i].id = i + 1;
		philos[i].data = data;
		philos[i].init_time = 0;
		philos[i].last_meal = 0;
		philos[i].start_sleep = 0;
	}
	if (!init_alloc_memory(&philos))
		return (NULL);
	return (philos);
}

static int	init_alloc_memory(t_philos **phi)
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


void free_all_pointers(void *p1, void *p2, void *p3)
{
	if (p1)
		free(p1);
	if (p2)
		free(p2);
	if (p3)
		free(p3);
}
