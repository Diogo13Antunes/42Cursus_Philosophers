/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogoantunes <diogoantunes@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:03:52 by diogoantune       #+#    #+#             */
/*   Updated: 2022/08/09 12:50:17 by diogoantune      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	print_args(char **args)
{
	printf("================== ARGS ==================\n\n");
	printf("Number of Philos = [ %s ]\n", args[1]);
	printf("Time to die      = [ %s ]\n", args[2]);
	printf("Time to eat      = [ %s ]\n", args[3]);
	printf("Time of sleep    = [ %s ]\n", args[4]);
	if (args[5])
		printf("Number of eats   = [ %s ]\n", args[5]);
	printf("\n==========================================\n");
}

static void	print_philos(t_philos **philos)
{
	int	i;

	i = 0;
	while (philos[i])
	{
		printf("[%d] ", i);
		printf("[%d] ", philos[i]->t_life);
		printf("[%d] ", philos[i]->t_eat);
		printf("[%d] ", philos[i]->t_sleep);
		printf("[%d] ", philos[i]->nbr_eats);
		printf("\n");
		i++;
	}
}

int	main(int ac, char **av)
{
	t_philos	**philosopher;

	if (check_arguments(ac, av))
		return (-1);
	print_args(av);
	philosopher = start_philos(av);
	philosopher = init_threads(philosopher, ft_atoi(av[1]));
	print_philos(philosopher);
}
