/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:27:10 by dcandeia          #+#    #+#             */
/*   Updated: 2022/10/11 17:12:12 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_forks(t_philos *philos)
{
	int	i;
	int	nbr_philos;

	i = -1;
	nbr_philos = philos->nbr_philos;
	while (++i < nbr_philos)
	{
		if (pthread_mutex_init(&philos[i].right.lock, NULL))
			return (-1);
		philos[i].right.status = FORK_AVAILABLE;
		philos[i + 1].left = &philos[i].right;
	}
	philos[0].left = &philos[nbr_philos - 1].right;
	return (0);
}

t_philos	*init_threads(t_philos *philos, int nbr_philos)
{
	int	i;

	i = -1;
	while (++i < nbr_philos)
		if (pthread_create(&philos[i].philo, NULL, &routine, &philos[i]))
			return (NULL);
	i = -1;
	while (++i < nbr_philos)
		if (pthread_join(philos[i].philo, NULL))
			return (NULL);
	return (philos);
}

t_philos	*start_philos(t_data data)
{
	t_philos		*philos;

	philos = malloc(sizeof(t_philos) * data.nbr_philos);
	if (!philos)
		return (NULL);
	philos = init_data(philos, data);
	if (!philos)
		return (NULL);
	if (init_forks(philos))
		return (NULL);
	return (philos);
}
