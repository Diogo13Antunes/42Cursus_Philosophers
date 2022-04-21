/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:01:46 by dcandeia          #+#    #+#             */
/*   Updated: 2022/04/19 15:18:33 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Arguments
> [number_of_philosopher]
> [time_to_die]
> [time_to_eat]
> [time_to_sleep]
> [number_of_times_each_philosopher_must_eat] // Optional
*/

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	if (argc > 6 || argc < 5)
		errors(NULL);
	check_args(argv);
	return (0);
}
