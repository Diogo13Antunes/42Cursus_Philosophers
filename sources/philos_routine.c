/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:24:47 by diogoantune       #+#    #+#             */
/*   Updated: 2022/10/21 11:02:15 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	wait_to_init(t_philos *philos);
static int	is_everyone_alive(t_philos *phi);

void	*routine(void *philos)
{
	t_philos		*phi;
	int				status;

	phi = (t_philos *)philos;
	wait_to_init(phi);
	status = STATUS_TAKING_FORK;
	if (phi->id % 2 != 0)
		usleep(2000);
	if (phi->id % 2 != 0 && phi->id == phi->data.nbr_philos)
		usleep(500);
	while (status != STATUS_DEAD && status != STATUS_EXIT)
	{
		usleep(100);
		if (!is_everyone_alive(phi))
			status = STATUS_DEAD;
		else if (status == STATUS_TAKING_FORK)
			status = action_pickup_forks(phi);
		else if (status == STATUS_EATING)
			status = action_eating(phi);
		else if (status == STATUS_SLEEPING)
			status = action_sleeping(phi);
	}
	return (NULL);
}

static int	is_everyone_alive(t_philos *phi)
{
	pthread_mutex_lock(phi->main_locker);
	if (get_current_time() - phi->last_meal >= (unsigned long)phi->data.t_life
		|| *phi->is_alive == DEAD)
	{
		if (*phi->is_alive == ALIVE)
		{
			*phi->is_alive = DEAD;
			action_died(phi);
		}
		pthread_mutex_unlock(phi->main_locker);
		return (0);
	}
	else
		pthread_mutex_unlock(phi->main_locker);
	return (1);
}

static void	wait_to_init(t_philos *philos)
{
	int	nbr_philos;

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
		else
			pthread_mutex_unlock(philos->main_locker);
	}
	philos->init_time = get_current_time();
	philos->last_meal = philos->init_time;
}
