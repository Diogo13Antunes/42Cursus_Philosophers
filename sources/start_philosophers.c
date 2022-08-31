/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:27:10 by dcandeia          #+#    #+#             */
/*   Updated: 2022/08/31 16:08:18 by dcandeia         ###   ########.fr       */
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
	int				i;
	// unsigned int	*start_t;
	pthread_mutex_t	*begin;

	i = -1;
	begin = malloc(sizeof(pthread_mutex_t));
	if (!begin)
		return (NULL);
	pthread_mutex_init(begin, NULL);
	pthread_mutex_lock(begin);
	while (++i < nbr_philos)
	{
		philos[i].start = begin;
		if (pthread_create(&philos[i].philo, NULL, &routine, &philos[i]))
			return (NULL);
	}
	pthread_mutex_unlock(philos[0].start);
	i = -1;
	while (++i < nbr_philos)
		if (pthread_join(philos[i].philo, NULL))
			return (NULL);
	return (philos);
}

t_philos	*start_philos(t_data data)
{
	t_philos		*philos;
	int				i;

	philos = malloc(sizeof(t_philos) * data.nbr_philos);
	if (!philos)
		return (NULL);
	i = -1;
	while (++i < data.nbr_philos)
	{
		philos[i].id = i + 1;
		philos[i].t_life = data.t_life;
		philos[i].t_eat = data.t_eat;
		philos[i].t_sleep = data.t_sleep;
		philos[i].nbr_eats = data.nbr_eats;
	}
	return (philos);
}
