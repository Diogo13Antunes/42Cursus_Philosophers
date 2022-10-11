/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:16:52 by dcandeia          #+#    #+#             */
/*   Updated: 2022/10/11 17:21:49 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	update_fork_status(pthread_mutex_t *mutex, int *status, int value);

void	action_pickup_forks(t_philos *phi)
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

void	action_eating(t_philos *phi)
{
	int nbr_forks;

	usleep(phi->t_eat * 1000);
	nbr_forks = 0;
	pthread_mutex_lock(&phi->right.lock);
	if (phi->right.status == FORK_UNAVAILABLE)
		nbr_forks++;
	pthread_mutex_unlock(&phi->right.lock);
	pthread_mutex_lock(&phi->left->lock);
	if (phi->left->status == FORK_UNAVAILABLE)
		nbr_forks++;
	pthread_mutex_unlock(&phi->left->lock);
	if (nbr_forks == 2)
	{
		phi->last_meal = get_current_time();
		print_philos_actions(phi, ACTION_EATING);
		/* criar timer para largar os garfos */
		action_drop_forcks(phi);
	}
}

/* free variables */
void	action_died(t_philos *phi)
{
	print_philos_actions(phi, ACTION_DIED);
	return ;
}

static void	update_fork_status(pthread_mutex_t *mutex, int *status, int value)
{
	pthread_mutex_lock(mutex);
	*status = value;
	pthread_mutex_unlock(mutex);
}

