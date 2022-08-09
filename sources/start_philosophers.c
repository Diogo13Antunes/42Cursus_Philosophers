/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogoantunes <diogoantunes@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:00:14 by diogoantune       #+#    #+#             */
/*   Updated: 2022/08/09 11:39:09 by diogoantune      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*send_msg(void *a)
{
	(void)a;
	printf("Creating thread...\n");
	sleep(2);
	printf("Thread created!\n");
	return (NULL);
}

t_philos	**init_threads(t_philos **philos, int nbr_philos)
{
	int	i;

	i = -1;
	while (++i < nbr_philos)
		if (pthread_create(&philos[i]->philo, NULL, &send_msg, NULL))
			return (NULL);
	i = -1;
	while (++i < nbr_philos)
		if (pthread_join(philos[i]->philo, NULL))
			return (NULL);
	return (philos);
}

t_philos	**start_philos(char **args)
{
	t_philos	**philos;
	int			i;
	int			nbr_philos;

	if (!args)
		return (NULL);
	nbr_philos = ft_atoi(args[1]);
	philos = malloc(sizeof(t_philos *) * (nbr_philos + 1));
	i = -1;
	while (++i < nbr_philos)
	{
		philos[i] = malloc(sizeof(t_philos));
		philos[i]->t_life = ft_atoi(args[2]);
		philos[i]->t_eat = ft_atoi(args[3]);
		philos[i]->t_sleep = ft_atoi(args[4]);
		if (args[5])
			philos[i]->nbr_eats = ft_atoi(args[5]);
		else
			philos[i]->nbr_eats = 0;
	}
	philos[nbr_philos] = NULL;
	return (philos);
}
