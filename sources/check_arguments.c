/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:27:20 by diogoantune       #+#    #+#             */
/*   Updated: 2022/10/21 11:06:49 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_isnbr(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			i++;
		if (str[i] == '-' || str[i] == '+')
			return (-1);
	}
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (-1);
		i++;
	}
	return (0);
}

static int	check_nbrs(char **av)
{
	long int	nbr;
	int			i;

	i = 1;
	while (av[i])
	{
		if (ft_isnbr(av[i]))
			return (-1);
		nbr = ft_atoi_long(av[i]);
		if (nbr <= 0 || nbr > 2147483647)
			return (-1);
		i++;
	}
	return (0);
}

int	check_arguments(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		put_error_msg("Invalid number of Arguments.");
		return (-1);
	}
	else if (check_nbrs(av))
	{
		put_error_msg("Invalid Arguments");
		return (-1);
	}
	return (0);
}
