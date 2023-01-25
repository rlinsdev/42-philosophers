/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:02:00 by rlins             #+#    #+#             */
/*   Updated: 2023/01/25 08:08:14 by rlins            ###   ########.fr       */
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

# define ERR_PARAM "Wrong arguments. Check the subject and try again.\n"
# define ERR_THREAD	"Error: Could not create thread.\n"
# define ERR_MALLOC	"Error: Could not allocate memory.\n"
# define ERR_MUTEX	"Error: Could not create mutex.\n"

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
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		time_must_eat;
	t_philo		**philo;
	bool		dinner_stop;
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
 * @return long value
 */
long	ft_ato_long(const char *str);

/**
 * @brief Check if argument is a valid digit
 * @param c
 * @return boolean
 */
bool	ft_isdigit(int c);

/**
 * @brief Initialize the structure Dinner
 * @param argc Arg Count
 * @param argv Arg Vectors
 * @param dinner Dinner structure by param
 * @return t_dinner* Return this structure or null if error.
 */
t_dinner *init_dinner(int argc, char **argv, t_dinner *dinner);

/**
 * @brief Handle msg error. Create Malloc / Mutex and Thread
 * @param str String with error message
 * @param dinner Object to be cleaned
 */
void	*error_msg_null(char *str, t_dinner *dinner);

#endif
