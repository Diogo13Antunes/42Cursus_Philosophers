/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:13:14 by dcandeia          #+#    #+#             */
/*   Updated: 2022/10/20 16:48:07 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	pthread_mutex_t	*mutex;
	int				*wait_initialize;
	int				*is_alive;
	int				i;

	is_alive = malloc(sizeof(int));
	wait_initialize = malloc(sizeof(int));
	mutex = malloc(sizeof(pthread_mutex_t));
	if (!is_alive || !mutex || !wait_initialize)
		return (NULL);
	pthread_mutex_init(mutex, NULL);
	*is_alive = 1;
	*wait_initialize = 1;
	i = -1;
	while (++i < data.nbr_philos)
	{
		philos[i].id = i + 1;
		philos[i].main_locker = mutex;
		philos[i].init_timer_bool = wait_initialize;
		philos[i].data = data;
		philos[i].init_time = 0;
		philos[i].last_meal = 0;
		philos[i].is_alive = is_alive;
	}
	return (philos);
}
