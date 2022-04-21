/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:55:06 by dcandeia          #+#    #+#             */
/*   Updated: 2022/04/19 12:35:37 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	errors(char *str)
{
	if (str == NULL)
	{
		printf("Correct Usage : ");
		printf("./philo [number_of_philosopher] [time_to_die] [time_to_eat]");
		printf(" [time_to_sleep] (number_of_times_each_philosopher_must_eat)\n");
	}
	else
		printf("%s", str);
	exit(0);
}
