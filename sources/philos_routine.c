/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piriquito <piriquito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:24:47 by diogoantune       #+#    #+#             */
/*   Updated: 2022/10/18 15:14:49 by piriquito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	wait_to_init(t_philos *philos);
static int	is_everyone_alive(t_philos *phi);
static int	is_everyone_full_eat(t_philos *phi);

void	*routine(void *philos)
{
	t_philos		*phi;
	int				status;

	phi = (t_philos *)philos;
	wait_to_init(phi);
	phi->init_time = get_current_time();
	phi->last_meal = phi->init_time;
	status = STATUS_TAKING_FORK;
	if (phi->id % 2 != 0)
		usleep(2000);
	while (status != STATUS_DEAD)
	{
		if (!is_everyone_alive(phi))
			status = action_died(phi);
		if (!is_everyone_full_eat(phi))
			status = STATUS_DEAD;
		if (status == STATUS_TAKING_FORK)
			status = action_pickup_forks(phi);
		else if (status == STATUS_EATING)
			status = action_eating(phi);
		else if (status == STATUS_SLEEPING)
			print_philos_actions(phi, ACTION_SLEEPING);
		else
			print_philos_actions(phi, ACTION_THINKING);
	}
	return (NULL);
}

static int	is_everyone_alive(t_philos *phi)
{
	pthread_mutex_lock(phi->main_locker);
	if (phi->is_alive == 0)
	{
		pthread_mutex_unlock(phi->main_locker);
		return (0);	
	}
	if (get_current_time() - phi->last_meal > (unsigned long)phi->data.t_life)
	{
		*phi->is_alive = 0;
		pthread_mutex_unlock(phi->main_locker);
		return (0);
	}
	pthread_mutex_unlock(phi->main_locker);
	return (1);
}

static int	is_everyone_full_eat(t_philos *philos)
{
	pthread_mutex_lock(philos->main_locker);
	if (philos->data.nbr_eats == 0)
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

	nbr_philos = philos->data.nbr_philos;
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
