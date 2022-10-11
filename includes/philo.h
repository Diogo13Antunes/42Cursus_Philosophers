/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:53:07 by dcandeia          #+#    #+#             */
/*   Updated: 2022/10/11 09:44:00 by dcandeia         ###   ########.fr       */
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

// # define ACTION_TAKE__FORK	"has taken a fork"
# define ACTION_TAKE_LEFT_FORK	"\e[1;36mhas taken a left fork\e[0m"
# define ACTION_TAKE_RIGHT_FORK	"\e[1;36mhas taken a right fork\e[0m"
# define ACTION_EATING			"\e[1;33mis eating\e[0m"
# define ACTION_SLEEPING		"\e[1;34mis sleeping\e[0m"
# define ACTION_THINKING		"\e[1;35mis thinking\e[0m"
# define ACTION_DIED			"\e[1;31mdied\e[0m"

//================================= Structs ====================================

typedef struct s_data
{
	int				nbr_philos;
	int				t_eat;
	int				t_sleep;
	int				t_life;
	int				nbr_eats;
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
	unsigned long	t_eat;
	unsigned long	t_sleep;
	unsigned long	t_life;
	int				nbr_eats;
	pthread_t		philo;
	t_fork			*left;
	t_fork			right;
	int				*start_locker;
	unsigned long	init_time;
	unsigned long	last_meal;
	int				*is_alive;
}				t_philos;

//================================ Prototypes ==================================

/* str_to_int_converters.c */
long int			ft_atoi_long(const char *str);
int					ft_atoi(const char *str);

/* error_handler.c */
void				put_error_msg(char *msg);

/* check_arguments.c */
int					check_arguments(int ac, char **av);

/* start_philosophers.c */
t_philos			*start_philos(t_data data);
t_philos			*init_threads(t_philos *philos, int nbr_philos);
unsigned long		get_time(void);

/* philos_routine.c */
void				*routine(void *philos);

/* set_arguments.c */
void				set_data(t_data *data, char **args);
t_philos			*init_data(t_philos *philos, t_data data);

/* utils.c */
void				ft_putstr_fd(char *str, int fd);
void				print_philos_actions(t_philos *philo, char *action);

/* utils_time.c */
unsigned long int	get_current_time(void);
void				print_time(t_philos *philos);
int					init_timer(t_philos *philos);

/* actions_utils.c */
void				action_pickup_forks_evens(t_philos *phi);
void				action_pickup_forks_odds(t_philos *phi);
void				action_drop_forcks(t_philos *phi);
void				action_eating(t_philos *phi);
void				action_died(t_philos *phi);

//==============================================================================

#endif
