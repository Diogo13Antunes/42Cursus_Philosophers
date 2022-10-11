/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:16:52 by dcandeia          #+#    #+#             */
/*   Updated: 2022/10/11 09:46:33 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	action_pickup_forks_odds(t_philos *phi)
{
	pthread_mutex_lock(&phi->left->lock);
	phi->left->status = 1;
	print_philos_actions(phi, ACTION_TAKE_LEFT_FORK);
	pthread_mutex_lock(&phi->right.lock);
	phi->right.status = 1;
	print_philos_actions(phi, ACTION_TAKE_RIGHT_FORK);
}

void	action_pickup_forks_evens(t_philos *phi)
{
	pthread_mutex_lock(&phi->right.lock);
	phi->right.status = 1;
	print_philos_actions(phi, ACTION_TAKE_RIGHT_FORK);
	pthread_mutex_lock(&phi->left->lock);
	phi->left->status = 1;
	print_philos_actions(phi, ACTION_TAKE_LEFT_FORK);
}

void	action_drop_forcks(t_philos *phi)
{
	pthread_mutex_unlock(&phi->right.lock);
	phi->right.status = 0;
	pthread_mutex_unlock(&phi->left->lock);
	phi->left->status = 0;
}

void	action_eating(t_philos *phi)
{
	if (!phi->right.status || !phi->left->status)
		return ;
	phi->last_meal = get_current_time();
	print_philos_actions(phi, ACTION_EATING);
	usleep(phi->t_eat * 1000);
	action_drop_forcks(phi);
}

/* free variables */
void	action_died(t_philos *phi)
{
	print_philos_actions(phi, ACTION_DIED);
	return ;
}
