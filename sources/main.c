/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogoantunes <diogoantunes@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:03:52 by diogoantune       #+#    #+#             */
/*   Updated: 2022/08/03 11:02:08 by diogoantune      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
Arguments
> [number_of_philosopher]
> [time_to_die]
> [time_to_eat]
> [time_to_sleep]
> [number_of_times_each_philosopher_must_eat] // Optional
*/

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (check_arguments(ac, av))
		return (-1);
	else
		printf("ARGS > [OK]\n");
	while (av[i])
	{
		printf("[%s]\n", av[i]);
		i++;
	}
}
