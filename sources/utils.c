/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:15:26 by piriquito         #+#    #+#             */
/*   Updated: 2022/10/21 17:06:24 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], fd);
		i++;
	}
}

void	print_philos_actions(t_philos *philo, char *action)
{
	unsigned long	time;

	pthread_mutex_lock(philo->main_locker);
	time = get_current_time() - philo->data.init_time;
	printf("%ld %d %s\n", time, philo->id, action);
	pthread_mutex_unlock(philo->main_locker);
}
