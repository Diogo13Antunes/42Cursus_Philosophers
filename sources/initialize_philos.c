/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_philos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:25:24 by dcandeia          #+#    #+#             */
/*   Updated: 2022/04/21 16:37:17 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*init_variables(t_arg *args)
{
	int	i;

	i = 0;
	while (i < args->nbr_philo)
	{
		if (pthread_mutex_init(&(args->philos)[i].fork_right, NULL) != 0)
		{
			while (i >= 0)
			{
				pthread_mutex_destroy(&(args->philos)[i].fork_right);
				i--;
			}
			free (args->philos);
			return (NULL);
		}
		(args->philos)[i].is_alive = 1;
		if (i != 0)
			((args->philos)[i].fork_left) = (&(args->philos)[i - 1].fork_left);
		i++;
	}
	((args->philos)[0].fork_left) = (&(args->philos)[i - 1].fork_left);
	return (args);
}

void	*init_philos(t_arg *args)
{
	int	a;

	a = 0;
	args->philos = (t_philo *)malloc(sizeof(t_philo) * args->nbr_philo);
	if (args->philos == NULL)
		return (NULL);
	if (pthread_mutex_init(&args->mutex_ph, NULL) != 0)
		return (NULL);
	if (!init_variables(&args))
	{
		pthread_mutex_destroy(&args->mutex_ph);
		return (NULL);
	}
	args->game_over = 0;
	
}
