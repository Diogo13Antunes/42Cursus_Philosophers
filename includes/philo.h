/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:53:07 by dcandeia          #+#    #+#             */
/*   Updated: 2022/04/19 15:33:49 by dcandeia         ###   ########.fr       */
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
# include <time.h>
# include <pthread.h>
//================================= Defines ====================================
# define TRUE	1
# define FALSE	0
//================================= Structs ====================================
typedef pthread_t		t_thread;
typedef pthread_mutex_t	t_mutex;
typedef struct s_arg
{
	int		nbr_philo;
	int		time_diw;
	int		time_eat;
	int		time_sleep;
	int		nbr_eats;
	int		game_over;
	t_mutex	m_philo;
	int		time_value;
}				t_arg;
//================================ Prototypes ==================================
void	errors(char *str);
void	check_args(char **argv);
//==============================================================================

#endif