/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogoantunes <diogoantunes@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:27:20 by diogoantune       #+#    #+#             */
/*   Updated: 2022/07/21 10:27:51 by diogoantune      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_isdigit(char **strs)
{
	int	i;
	int	ii;

	i = 0;
	while (strs[i])
	{
		ii = 0;
		while (strs[i][ii])
		{
			if (strs[i][ii] < 48 || strs[i][ii] > 57)
				return (-1);
			ii++;
		}
		i++;
	}
	return (0);
}

int	check_arguments(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		put_error_msg("Invalid number pf Arguments.");
		return (-1);	
	}
	if (ft_isdigit(av))
	{
		put_error_msg("All Arguments must be numbers.");
		return (-1);	
	}
	return (0);
}
