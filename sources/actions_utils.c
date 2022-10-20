/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:16:52 by dcandeia          #+#    #+#             */
/*   Updated: 2022/10/20 17:37:43 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	action_pickup_forks(t_philos *phi)
{
	phi->data.nbr_forks += pickup_right_fork(phi);
	phi->data.nbr_forks += pickup_left_fork(phi);
	if (phi->data.nbr_forks == 2)
	{
		phi->last_meal = get_current_time();
		phi->data.nbr_forks = 0;
		print_philos_actions(phi, ACTION_EATING);
		return (STATUS_EATING);
	}
	return (STATUS_TAKING_FORK);
}

int	action_eating(t_philos *phi)
{
	if (check_time_pass(phi->last_meal, phi->data.t_eat))
	{
		drop_forks(phi);
		phi->start_sleep = get_current_time();
		if (phi->data.nbr_eats != -1)
			phi->data.nbr_eats--;
		return (STATUS_SLEEPING);
	}
	return (STATUS_EATING);
}

int	action_sleeping(t_philos *phi)
{
	if (check_time_pass(phi->start_sleep, phi->data.t_sleep))
	{
		print_philos_actions(phi, ACTION_SLEEPING);
		return (STATUS_THINKING);
	}
	return (STATUS_SLEEPING);
}

int	action_thinking(t_philos *phi)
{
	print_philos_actions(phi, ACTION_THINKING);
	return (STATUS_TAKING_FORK);
}

/* free variables */
int	action_died(t_philos *phi)
{
	print_philos_actions(phi, ACTION_DIED);
	return (STATUS_DEAD);
}
