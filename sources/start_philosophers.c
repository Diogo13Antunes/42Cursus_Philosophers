/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piriquito <piriquito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:27:10 by dcandeia          #+#    #+#             */
/*   Updated: 2022/09/09 15:19:54 by piriquito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec / 1000 / 1000) + (time.tv_usec));
}

void	finish_threads(t_philos **philos, int nbr_philos)
{
	int	i;

	i = -1;
	while (++i < nbr_philos)
		if (pthread_join(philos[i]->philo, NULL))
			return ;
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
	return (philos);
}
