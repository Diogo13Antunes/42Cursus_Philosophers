/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogoantunes <diogoantunes@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:54:48 by diogoantune       #+#    #+#             */
/*   Updated: 2022/08/02 09:42:25 by diogoantune      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	put_error_msg(char *msg)
{
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\n", 1);
}
