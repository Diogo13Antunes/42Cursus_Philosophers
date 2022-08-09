/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogoantunes <diogoantunes@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:53:07 by dcandeia          #+#    #+#             */
/*   Updated: 2022/08/09 09:44:55 by diogoantune      ###   ########.fr       */
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

typedef struct s_philos
{
	int				t_eat;
	int				t_sleep;
	int				t_life;
	int				nbr_eats;
	pthread_t		philo;
	// pthread_mutex_t	f_right;
	// pthread_mutex_t	f_left;
}				t_philos;

//================================ Prototypes ==================================

/* str_to_int_converters.c */
long int	ft_atoi_long(const char *str);
int			ft_atoi(const char *str);

/* error_handler.c */
void		put_error_msg(char *msg);

/* check_arguments.c */
int			check_arguments(int ac, char **av);

/* start_philosophers.c */
t_philos	**start_philos(char **args);
int			init_threads(t_philos ***philos, int nbr_philos);

//==============================================================================

#endif