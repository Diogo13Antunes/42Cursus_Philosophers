/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:03:52 by diogoantune       #+#    #+#             */
/*   Updated: 2022/10/21 11:05:02 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_philos	*philosopher;
	t_data		data;

	if (check_arguments(ac, av))
		return (-1);
	set_data(&data, av);
	philosopher = start_philos(data);
	if (!philosopher)
		return (-1);
	philosopher = init_threads(philosopher, ft_atoi(av[1]));
	if (!philosopher)
		return (-1);
}
