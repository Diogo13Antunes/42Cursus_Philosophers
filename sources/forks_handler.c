/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:49:12 by dcandeia          #+#    #+#             */
/*   Updated: 2022/10/20 17:27:17 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	update_fork_status(pthread_mutex_t *mutex, int *status, int value);

void	drop_forks(t_philos *phi)
{
	pthread_mutex_lock(&phi->right.lock);
	if (phi->right.status == FORK_UNAVAILABLE)
	{
		pthread_mutex_unlock(&phi->right.lock);
		update_fork_status(&phi->right.lock,
			&phi->right.status, FORK_AVAILABLE);
	}
	else
		pthread_mutex_unlock(&phi->right.lock);
	pthread_mutex_lock(&phi->left->lock);
	if (phi->left->status == FORK_UNAVAILABLE)
	{
		pthread_mutex_unlock(&phi->left->lock);
		update_fork_status(&phi->left->lock,
			&phi->left->status, FORK_AVAILABLE);
	}
	else
		pthread_mutex_unlock(&phi->left->lock);
}

int	pickup_right_fork(t_philos *phi)
{
	pthread_mutex_lock(&phi->right.lock);
	if (phi->right.status == FORK_AVAILABLE)
	{
		pthread_mutex_unlock(&phi->right.lock);
		update_fork_status(&phi->right.lock,
			&phi->right.status, FORK_UNAVAILABLE);
		print_philos_actions(phi, ACTION_TAKE_RIGHT_FORK);
		return (1);
	}
	else
		pthread_mutex_unlock(&phi->right.lock);
	return (0);
}

int	pickup_left_fork(t_philos *phi)
{
	pthread_mutex_lock(&phi->left->lock);
	if (phi->left->status == FORK_AVAILABLE)
	{
		pthread_mutex_unlock(&phi->left->lock);
		update_fork_status(&phi->left->lock,
			&phi->left->status, FORK_UNAVAILABLE);
		print_philos_actions(phi, ACTION_TAKE_LEFT_FORK);
		return (1);
	}
	else
		pthread_mutex_unlock(&phi->left->lock);
	return (0);
}

static void	update_fork_status(pthread_mutex_t *mutex, int *status, int value)
{
	pthread_mutex_lock(mutex);
	*status = value;
	pthread_mutex_unlock(mutex);
}
