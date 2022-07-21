/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogoantunes <diogoantunes@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:53:07 by dcandeia          #+#    #+#             */
/*   Updated: 2022/07/21 10:28:10 by diogoantune      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
Arguments
> [number_of_philosopher]
> [time_to_die]
> [time_to_eat]
> [time_to_sleep]
> [number_of_times_each_philosopher_must_eat] // Optional
*/

//================================ Includes ====================================
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
//================================= Defines ====================================
# define TRUE	1
# define FALSE	0
//================================= Structs ====================================

//================================ Prototypes ==================================

/* error_handler.c */
void	put_error_msg(char *msg);

/* check_arguments.c */
int		check_arguments(int ac, char **av);

//==============================================================================

#endif