/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:53:07 by dcandeia          #+#    #+#             */
/*   Updated: 2022/04/21 17:26:31 by dcandeia         ###   ########.fr       */
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
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
//================================= Defines ====================================
# define TRUE	1
# define FALSE	0
//================================= Structs ====================================
typedef pthread_t		t_thread;
typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_timer;

typedef struct s_philo
{
	t_thread	phil;
	int			is_alive;
	int			last_meal;
	t_mutex		*fork_left;
	t_mutex		*fork_right;
	int			eat_counter;
}				t_philo;
typedef struct s_arg
{
	int			nbr_philo;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			nbr_eats;
	int			game_over;
	int			time_value;
	t_philo		*philos;
	t_mutex		mutex_ph;
}				t_arg;
//================================ Prototypes ==================================
int		ft_atoi(const char *str);
void	errors(char *str);
void	check_args(char **argv);
void	get_data(t_arg *data, int argc, char **argv);
void	*init_philos(t_arg *args);
//==============================================================================

#endif