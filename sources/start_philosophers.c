/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogoantunes <diogoantunes@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:00:14 by diogoantune       #+#    #+#             */
/*   Updated: 2022/08/10 14:31:02 by diogoantune      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec / 1000 / 1000) + (time.tv_usec));
}

t_philos	**init_threads(t_philos **philos, int nbr_philos)
{
	int	i;

	i = -1;
	while (++i < nbr_philos)
		if (pthread_create(&philos[i]->philo, NULL, &routine,\
		(void *)philos[i]))
			return (NULL);
	i = -1;
	while (++i < nbr_philos)
		if (pthread_join(philos[i]->philo, NULL))
			return (NULL);
	return (philos);
}

t_philos	**start_philos(char **args)
{
	t_philos		**philos;
	int				i;
	int				nbr_philos;
	pthread_mutex_t	*begin;
	unsigned int	*start_time;

	if (!args)
		return (NULL);
	nbr_philos = ft_atoi(args[1]);
	philos = malloc(sizeof(t_philos *) * (nbr_philos + 1));
	begin = malloc(sizeof(pthread_mutex_t));
	start_time = malloc(sizeof(unsigned int));
	*start_time = get_time();
	i = -1;
	while (++i < nbr_philos)
	{
		philos[i] = malloc(sizeof(t_philos));
		philos[i]->id = i + 1;
		philos[i]->t_life = ft_atoi(args[2]);
		philos[i]->t_eat = ft_atoi(args[3]);
		philos[i]->t_sleep = ft_atoi(args[4]);
		if (args[5])
			philos[i]->nbr_eats = ft_atoi(args[5]);
		else
			philos[i]->nbr_eats = 0;
		philos[i]->start = begin;
		philos[i]->time_start = start_time;
	}
	philos[nbr_philos] = NULL;
	pthread_mutex_init(begin, NULL);
	return (philos);
}
