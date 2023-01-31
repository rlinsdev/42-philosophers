/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:02:00 by rlins             #+#    #+#             */
/*   Updated: 2023/01/31 20:08:18 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // Printf
# include <stdlib.h> // Malloc
# include <pthread.h> //pthread_*, mutex
# include <unistd.h> // usleep
// # include <semaphore.h> // semaphore
# include <stdbool.h> //boolean
# include <limits.h> // long_max
# include <sys/time.h> // gettimeofday

# define ERR_PARAM "Wrong arguments. Check the subject and try again.\n"
# define ERR_THREAD	"Error: Could not create thread.\n"
# define ERR_MALLOC	"Error: Could not allocate memory.\n"
# define ERR_MUTEX	"Error: Could not create mutex.\n"

# ifndef PRETTY
#  define PRETTY 0
# endif

typedef struct s_table	t_table;

typedef enum e_state
{
	S_EATING,
	S_SLEEPING,
	S_THINKING,
	S_DEAD,
	S_FORK,
	S_END_DINNING
}	t_state;

typedef struct s_fork
{
	pthread_mutex_t	lock;
}					t_fork;

typedef struct s_philo
{
	pthread_t	thread;
	long		id;
	int		r_fork;
	int		l_fork;
	t_table		*table; // To Access data while thread running
	long		nbr_meals_done;
}				t_philo;

typedef struct s_table
{
	time_t			start_dinning;
	long			nbr_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_must_eat;
	t_philo			**philo;
	bool			dinner_end;
	pthread_mutex_t log_lock; // TODO: Rever se precis adeste cara...
}				t_table;

/**
 * @brief The threads will call this method. Will start all the routines.
 * Sleep / think / eat
 * @param data - Philosopher structure
 */
void *dinning_routines(void *data);

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
 * @brief Initialize the structure table
 * @param argc Arg Count
 * @param argv Arg Vectors
 * @return t_table* Return this structure or null if error.
 */
t_table *init_table(int argc, char **argv);

/**
 * @brief Handle msg error. Create Malloc / Mutex and Thread
 * @param str String with error message
 * @param table Object to be cleaned
 */
void	*error_msg_null(char *str, t_table *table);

/**
 * @brief Will return the DateTime now, but in milliseconds
 * @return integer value
 */
int datetime_now();

/**
 * @brief Will subtract the current DatetimeNow, from start dinning to log
 * the time in program
 * @param start_dinning
 * @return time_t
 */
int	get_time_ms(int start_dinning);

/**
 * @brief Log the status of current philo
 * @param philo Philosopher structure
 * @param status Status to log
 */
void	log_status(t_philo *philo, t_state status);

/**
 * @brief Sleep is not allowed. This wil simulate it.
 * Handle the time to sleep the thread
 * @param table
 * @param duration Milliseconds to thread sleep
 */
void	thread_sleep(t_table *table, time_t duration);

/**
 * @brief Will free all memory allocation in program
 * @param table Table structure
 * @return void*
 */
void	*free_table(t_table *table);

/**
 * @brief
 *
 * @param table
 */
// void free_mutex(t_table *table);

#endif
