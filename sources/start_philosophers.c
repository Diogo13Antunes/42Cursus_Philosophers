/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piriquito <piriquito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:27:10 by dcandeia          #+#    #+#             */
/*   Updated: 2022/09/15 10:30:34 by piriquito        ###   ########.fr       */
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
		pthread_mutex_init(&philos[i].right.lock, NULL);
		philos[i].right.status = 0;
	}
	i = -1;
	while (++i < nbr_philos)
		philos[i + 1].left = &philos[i].right;
	philos[0].left = &philos[nbr_philos - 1].right;
	return (0);
}

t_philos	*init_threads(t_philos *philos, int nbr_philos)
{
	int	i;

	i = -1;
	while (++i < nbr_philos)
	{
		if (pthread_create(&philos[i].philo, NULL, &routine, &philos[i]))
			return (NULL);
	}
	i = -1;
	while (++i < nbr_philos)
		if (pthread_join(philos[i].philo, NULL))
			return (NULL);
	return (philos);
}

t_philos	*start_philos(t_data data)
{
	t_philos		*philos;
	int				*init_locker;
	int				i;

	init_locker = malloc(sizeof(int));
	if (!init_locker)
		return (NULL);
	*init_locker = 2;
	philos = malloc(sizeof(t_philos) * data.nbr_philos);
	if (!philos)
		return (NULL);
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
		philos[i].time = NULL;
	}
	init_forks(philos);
	return (philos);
}
