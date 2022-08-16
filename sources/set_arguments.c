/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:13:14 by dcandeia          #+#    #+#             */
/*   Updated: 2022/08/16 17:24:01 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	set_data(t_data *data, char **args)
{
	data->nbr_philos = ft_atoi(args[1]);
	data->t_life = ft_atoi(args[2]);
	data->t_eat = ft_atoi(args[3]);
	data->t_sleep = ft_atoi(args[4]);
	if (args[5])
		data->nbr_eats = ft_atoi(args[5]);
	else
		data->nbr_eats = 0;
}
