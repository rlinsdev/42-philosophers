/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:02:00 by rlins             #+#    #+#             */
/*   Updated: 2023/01/24 10:46:21 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // Printf
# include <stdlib.h> // Malloc
# include <pthread.h> //pthread_*, mutex
# include <unistd.h> // Sleep
# include <semaphore.h> // semaphore
# include <stdbool.h> //boolean
# include <limits.h> // long_max

# define PARAM_ERROR "Wrong arguments. Check the subject and try again.\n"

typedef enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
	END_DINNER
}	t_state;

typedef struct s_fork
{
	pthread_mutex_t	lock;
}					t_fork;

typedef struct s_philo
{
	pthread_t	thread;
	long		id;
	t_fork		r_fork;
	t_fork		l_fork;
}				t_philo;

typedef struct s_dinner
{
	long		nbr_philo;
	t_philo		*philo;
}				t_dinner;

/**
 * @brief First method in project.
 * @param argc Arguments count
 * @param argv Arguments Vector
 * @return boolean
 */
bool	is_valid_args(int argc, char **argv);

/**
 * @brief Asc to Long function.
 * @param str String to be checked and transformed
 * @param error Bool variable to check error while calling
 * @return long value
 */
long	ft_ato_long(const char *str, bool *error);

/**
 * @brief Check if argument is a valid digit
 * @param c
 * @return boolean
 */
bool	ft_isdigit(int c);

#endif
