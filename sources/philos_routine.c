/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:24:47 by diogoantune       #+#    #+#             */
/*   Updated: 2022/10/10 16:32:48 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	wait_to_init(t_philos *philos);
static int	is_everyone_alive(t_philos *phi);
static int	is_everyone_full_eat(t_philos *phi);

void	*routine(void *philos)
{
	t_philos		*phi;

	phi = (t_philos *)philos;
	wait_to_init(phi);
	phi->init_time = get_current_time();
	while (1)
	{
		if (!is_everyone_alive(phi) || is_everyone_full_eat(phi))
		{
			if (phi->is_alive == 0)
				action_died(phi);
		}
		if (phi->id % 2 == 0)
			action_pickup_forks_odds(phi);
		else
			action_pickup_forks_evens(phi);
		action_eating(phi);
		break ;
	}
	print_philos_actions(phi, ACTION_THINKING);
	return (NULL);
}

static int	is_everyone_alive(t_philos *phi)
{
	pthread_mutex_t	*locker;

	locker = malloc(sizeof(pthread_mutex_t));
	if (get_current_time() - phi->last_meal
		> phi->t_life + get_current_time())
	{
		printf("Aqui\n");
		pthread_mutex_lock(locker);
		phi->is_alive = 0;
		pthread_mutex_unlock(locker);
		pthread_mutex_destroy(locker);
		return (0);
	}
	pthread_mutex_destroy(locker);
	return (1);
}

static int	is_everyone_full_eat(t_philos *phi)
{
	if (phi->nbr_eats == 0)
		return (0);
	else
		return (1);
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
