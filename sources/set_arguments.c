/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:13:14 by dcandeia          #+#    #+#             */
/*   Updated: 2022/10/10 14:38:44 by dcandeia         ###   ########.fr       */
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
}

t_philos	*init_data(t_philos *philos, t_data data)
{
	int	*init_locker;
	int	*is_alive;
	int	i;

	init_locker = malloc(sizeof(int));
	is_alive = malloc(sizeof(int));
	if (!init_locker || !is_alive)
		return (NULL);
	*init_locker = 2;
	*is_alive = 1;
	i = -1;
	while (++i < data.nbr_philos)
	{
		philos[i].id = i + 1;
		philos[i].start_locker = init_locker;
		philos[i].nbr_philos = data.nbr_philos;
		philos[i].t_life = data.t_life;
		philos[i].t_eat = data.t_eat;
		philos[i].t_sleep = data.t_sleep;
		philos[i].nbr_eats = data.nbr_eats;
		philos[i].init_time = 0;
		philos[i].last_meal = 0;
		philos[i].is_alive = is_alive;
	}
	return (philos);
}
