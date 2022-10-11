/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:24:47 by diogoantune       #+#    #+#             */
/*   Updated: 2022/10/11 17:03:59 by dcandeia         ###   ########.fr       */
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
	phi->last_meal = phi->init_time;
	if (phi->id % 2 != 0)
		usleep(2000);
	while (1)
	{
		pthread_mutex_lock(phi->main_locker);
		if (*phi->is_alive == -1)
		{
			pthread_mutex_unlock(phi->main_locker);
			break ;
		}
		pthread_mutex_unlock(phi->main_locker);
		if (!is_everyone_alive(phi))
		{
			action_died(phi);
			break ;
		}
		if (!is_everyone_full_eat(phi))
			break ;
		action_pickup_forks(phi);
		action_eating(phi);
	}
	return (NULL);
}

static int	is_everyone_alive(t_philos *phi)
{
	pthread_mutex_lock(phi->main_locker);
	if (get_current_time() - phi->last_meal > phi->t_life)
	{
		*phi->is_alive = -1;
		pthread_mutex_unlock(phi->main_locker);
		return (0);
	}
	pthread_mutex_unlock(phi->main_locker);
	return (1);
}

static int	is_everyone_full_eat(t_philos *philos)
{
	pthread_mutex_lock(philos->main_locker);
	if (philos->nbr_eats == 0)
	{
		pthread_mutex_unlock(philos->main_locker);
		return (0);
	}
	pthread_mutex_unlock(philos->main_locker);
	return (1);
}

static void	wait_to_init(t_philos *philos)
{
	int				nbr_philos;

	nbr_philos = philos->nbr_philos;
	while (1)
	{
		pthread_mutex_lock(philos->main_locker);
		if (philos->id == nbr_philos || *philos->init_timer_bool == 2)
		{
			*philos->init_timer_bool = 2;
			pthread_mutex_unlock(philos->main_locker);
			break ;
		}
		pthread_mutex_unlock(philos->main_locker);
	}
}
