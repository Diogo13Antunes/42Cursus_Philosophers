/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:24:47 by diogoantune       #+#    #+#             */
/*   Updated: 2022/08/31 17:30:46 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *philos)
{
	t_philos		phi;

	phi = *(t_philos *)philos;
	printf("Philo [%d] created!\n", phi.id);
	return (NULL);
}
