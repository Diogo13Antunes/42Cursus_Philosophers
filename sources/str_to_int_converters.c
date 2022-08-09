/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_int_converters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogoantunes <diogoantunes@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 09:40:16 by diogoantune       #+#    #+#             */
/*   Updated: 2022/08/09 09:44:00 by diogoantune      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	ft_atoi_long(const char *str)
{
	int			sinal;
	long int	numero;
	int			i;

	i = 0;
	sinal = 1;
	numero = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sinal *= -1;
		i++;
		if (str[i] == '-' || str[i] == '+')
			return (0);
	}
	while (str[i] >= 48 && str[i] <= 57)
		numero = (numero * 10) + (str[i++] - 48);
	return (numero * sinal);
}

int	ft_atoi(const char *str)
{
	int	sinal;
	int	numero;
	int	i;

	i = 0;
	sinal = 1;
	numero = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sinal *= -1;
		i++;
		if (str[i] == '-' || str[i] == '+')
			return (0);
	}
	while (str[i] >= 48 && str[i] <= 57)
		numero = (numero * 10) + (str[i++] - 48);
	return (numero * sinal);
}
