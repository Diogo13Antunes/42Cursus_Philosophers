/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piriquito <piriquito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:53:07 by dcandeia          #+#    #+#             */
/*   Updated: 2022/09/09 13:17:15 by piriquito        ###   ########.fr       */
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

typedef struct s_data
{
	int			nbr_philos;
	int			t_eat;
	int			t_sleep;
	int			t_life;
	int			nbr_eats;
}				t_data;

typedef struct s_fork
{
	int				status;
	pthread_mutex_t	lock;
}				t_fork;

typedef struct s_philos
{
	int				id;
	int				nbr_philos;
	int				t_eat;
	int				t_sleep;
	int				t_life;
	int				nbr_eats;
	pthread_t		philo;
	t_fork			*left;
	t_fork			right;
	int				*start_locker;
}				t_philos;

//================================ Prototypes ==================================

/* str_to_int_converters.c */
long int		ft_atoi_long(const char *str);
int				ft_atoi(const char *str);

/* error_handler.c */
void			put_error_msg(char *msg);

/* check_arguments.c */
int				check_arguments(int ac, char **av);

/* start_philosophers.c */
t_philos		*start_philos(t_data data);
t_philos		*init_threads(t_philos *philos, int nbr_philos);
unsigned long	get_time(void);

/* philos_routine.c */
void			*routine(void *philos);

/* set_arguments.c */
void			set_data(t_data *data, char **args);

/* utils.c */
void			ft_putstr_fd(char *str, int fd);

//==============================================================================

#endif