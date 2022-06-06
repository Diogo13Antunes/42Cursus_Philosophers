/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:01:46 by dcandeia          #+#    #+#             */
/*   Updated: 2022/04/21 14:29:12 by dcandeia         ###   ########.fr       */
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

void	print_args(t_arg args)
{
	printf("nbr_philos = %d\n", args.nbr_philo);
	printf("time_die = %d\n", args.time_die);
	printf("time_eat = %d\n", args.time_eat);
	printf("time_skeeo = %d\n", args.time_sleep);
	if (args.nbr_eats)
		printf("nbr_eats = %d\n", args.nbr_eats);
	return ;
}

int	main(int argc, char **argv)
{
	t_arg	args;

	if (argc > 6 || argc < 5)
		errors(NULL);
	check_args(argv);
	get_data(&args, argc, argv);
	print_args(args);
	if (!init_pholos(&args))
		errors("Error\n");
	return (0);
}
