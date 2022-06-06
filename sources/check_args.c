/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:51:24 by dcandeia          #+#    #+#             */
/*   Updated: 2022/04/21 10:35:04 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	is_number(char **str)
{
	int	i;
	int	a;

	i = 1;
	while (str[i])
	{
		a = 0;
		while (str[i][a])
		{
			if ((str[i][a] >= 9 && str[i][a] <= 13)
				|| (str[i][a] > 47 && str[i][a] < 58)
				|| str[i][a] == 32 || str[i][a] == 43 || str[i][a] == 45)
				a++;
			else
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

static int	check_signal(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	check_args(char **argv)
{
	if (is_number(argv) != TRUE)
		errors("Arguments are not numbers!\n");
	if (check_signal(argv) != TRUE)
		errors("Arguments are not greater than 0!\n");
	return ;
}
