/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:53:07 by dcandeia          #+#    #+#             */
/*   Updated: 2022/10/24 16:30:33 by dcandeia         ###   ########.fr       */
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

# define FORK_AVAILABLE		0
# define FORK_UNAVAILABLE	1

// # define ACTION_TAKE__FORK	"has taken a fork"
// # define ACTION_TAKE_LEFT_FORK	"has taken a left fork"
// # define ACTION_TAKE_RIGHT_FORK	"has taken a right fork"
# define ACTION_TAKE_LEFT_FORK	"has taken a fork"
# define ACTION_TAKE_RIGHT_FORK	"has taken a fork"
# define ACTION_EATING			"is eating"
# define ACTION_SLEEPING		"is sleeping"
# define ACTION_THINKING		"is thinking"
# define ACTION_DIED			"died"

# define STATUS_TAKING_FORK	0
# define STATUS_EATING		1
# define STATUS_SLEEPING	2
# define STATUS_THINKING	3
# define STATUS_DEAD		4
# define STATUS_EXIT		5

# define ALIVE				1
# define DEAD				2

//================================= Structs ====================================

typedef struct s_data
{
	int				nbr_philos;
	int				t_eat;
	int				t_sleep;
	int				t_life;
	int				nbr_eats;
	int				nbr_forks;
	unsigned long	init_time;
}				t_data;

typedef struct s_fork
{
	int				status;
	pthread_mutex_t	lock;
}				t_fork;

typedef struct s_philos
{
	int				id;
	t_data			data;
	pthread_t		philo;
	t_fork			*left;
	t_fork			right;
	pthread_mutex_t	*main_locker;
	int				*init_timer_bool;
	unsigned long	last_meal;
	unsigned long	start_sleep;
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

/* alloc_mem.c */
int					init_alloc_memory(t_philos **phi);
void				free_all_pointers(void *p1, void *p2, void *p3);
int					free_allocated_memory(t_philos *philos);

/* philos_routine.c */
void				*routine(void *philos);
int					is_everyone_alive(t_philos *phi);

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
int					check_time_pass(unsigned long time, unsigned long t_pass);

/* actions_utils.c */
int					action_pickup_forks(t_philos *phi);
int					action_eating(t_philos *phi);
int					action_died(t_philos *phi);
int					action_sleeping(t_philos *phi);

/* forks_handler.c */
int					pickup_right_fork(t_philos *phi);
int					pickup_left_fork(t_philos *phi);
void				drop_forks(t_philos *phi);

//==============================================================================

#endif
