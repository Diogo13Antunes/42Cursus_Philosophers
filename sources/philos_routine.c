/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:24:47 by diogoantune       #+#    #+#             */
/*   Updated: 2022/09/23 11:31:57 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	print_philos_actions(t_philos *philo, char *action);
static void	wait_to_init(t_philos *philos);

void	*routine(void *philos)
{
	t_philos		*phi;

	phi = (t_philos *)philos;
	wait_to_init(phi);
	init_timer(phi);
	print_philos_actions(phi, ACTION_THINKING);
	return (NULL);
}

static void	wait_to_init(t_philos *philos)
{
	int				nbr_philos;
	pthread_mutex_t	lock;

	nbr_philos = philos->nbr_philos;
	pthread_mutex_init(&lock, NULL);
	while (*philos->start_locker == 2)
	{
		if (philos->id == nbr_philos)
		{
			pthread_mutex_lock(&lock);
			*philos->start_locker = 1;
			pthread_mutex_unlock(&lock);
		}
	}
	pthread_mutex_destroy(&lock);
}

static void	print_philos_actions(t_philos *philo, char *action)
{
	unsigned long	time;
	pthread_mutex_t	lock;

	pthread_mutex_init(&lock, NULL);
	pthread_mutex_lock(&lock);
	time = get_current_time() - *(philo->time);
	printf("%ld %d %s\n", time, philo->id, action);
	pthread_mutex_unlock(&lock);
	pthread_mutex_destroy(&lock);
}
