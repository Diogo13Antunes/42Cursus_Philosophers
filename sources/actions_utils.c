/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piriquito <piriquito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:16:52 by dcandeia          #+#    #+#             */
/*   Updated: 2022/10/18 15:19:24 by piriquito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	update_fork_status(pthread_mutex_t *mutex, int *status, int value);

int	action_pickup_forks(t_philos *phi)
{
	pthread_mutex_lock(phi->main_locker);
	if (phi->right.status == FORK_AVAILABLE)
	{
		update_fork_status(&phi->right.lock,
			&phi->right.status, FORK_UNAVAILABLE);
		print_philos_actions(phi, ACTION_TAKE_RIGHT_FORK);
	}
	if (phi->left->status == FORK_AVAILABLE)
	{
		update_fork_status(&phi->left->lock,
			&phi->left->status, FORK_UNAVAILABLE);
		print_philos_actions(phi, ACTION_TAKE_LEFT_FORK);
	}
	pthread_mutex_unlock(phi->main_locker);
	return (STATUS_EATING);
}

void	action_drop_forcks(t_philos *phi)
{
	pthread_mutex_lock(phi->main_locker);
	if (phi->left->status == FORK_UNAVAILABLE)
		update_fork_status(&phi->left->lock,
			&phi->left->status, FORK_AVAILABLE);
	if (phi->right.status == FORK_UNAVAILABLE)
		update_fork_status(&phi->right.lock,
			&phi->right.status, FORK_AVAILABLE);
	pthread_mutex_unlock(phi->main_locker);
}

int	action_eating(t_philos *phi)
{
	int	nbr_forks;

	nbr_forks = 0;
	// pthread_mutex_lock(&phi->right.lock);
	if (phi->right.status == FORK_UNAVAILABLE
		&& phi->left->status == FORK_UNAVAILABLE)
		nbr_forks += 2;
	// pthread_mutex_unlock(&phi->right.lock);
	if (nbr_forks == 2)
	{
		phi->last_meal = get_current_time();
		print_philos_actions(phi, ACTION_EATING);
		usleep(phi->data.t_eat * 1000);
		/* criar timer para largar os garfos */
		action_drop_forcks(phi);
	}
	return (STATUS_SLEEPING);
}

/* free variables */
int	action_died(t_philos *phi)
{
	print_philos_actions(phi, ACTION_DIED);
	return (STATUS_DEAD);
}

static void	update_fork_status(pthread_mutex_t *mutex, int *status, int value)
{
	pthread_mutex_lock(mutex);
	*status = value;
	pthread_mutex_unlock(mutex);
}
