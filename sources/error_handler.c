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
	int	i;

	i = 0;
	write(STDERR_FILENO, "Error: ", 7);
	while (msg[i])
		write(STDERR_FILENO, &msg[i++], 1);
	write(STDERR_FILENO, "\n", 1);
}
