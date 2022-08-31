/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:03:52 by diogoantune       #+#    #+#             */
/*   Updated: 2022/08/31 16:01:49 by dcandeia         ###   ########.fr       */
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
	printf("\n");
}

// static void	print_philos(t_philos *philos, int nbr_philos)
// {
// 	int	i;

// 	i = 0;
// 	printf("\n");
// 	printf("================== PHILOS ==================\n\n");
// 	while (i < nbr_philos)
// 	{
// 		printf("[%d] ", philos[i].id);
// 		printf("[%d] ", philos[i].t_life);
// 		printf("[%d] ", philos[i].t_eat);
// 		printf("[%d] ", philos[i].t_sleep);
// 		printf("[%d] ", philos[i].nbr_eats);
// 		printf("\n");
// 		i++;
// 	}
// 	printf("\n============================================\n");
// }

int	main(int ac, char **av)
{
	t_philos	*philosopher;
	t_data		data;

	if (check_arguments(ac, av))
		return (-1);
	print_args(av);
	set_data(&data, av);
	philosopher = start_philos(data);
	philosopher = init_threads(philosopher, ft_atoi(av[1]));
	// print_philos(philosopher, data.nbr_philos);
}
