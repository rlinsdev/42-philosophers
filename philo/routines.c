/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:22:12 by rlins             #+#    #+#             */
/*   Updated: 2023/02/02 12:29:30 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void *lonely_philo(t_philo *philo);
static void header_pretty(t_philo *philo);
static void	keep_thinking(t_philo *philo);
static void keep_eating(t_philo *philo);
static void keep_sleeping(t_philo *philo);

void *dinning_routines(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	if (philo->table->time_must_eat == 0)
		return (NULL);

	set_last_meal_prop(philo, philo->table->start_dinning);

	if (philo->table->nbr_philo == 1)
		return (lonely_philo(philo));
	// printf("[%li]\n", (philo->id % 2));
	if (philo->id % 2)
		keep_thinking(philo);

	while (has_dinner_finish(philo->table) == false)
	{
		keep_eating(philo);
		keep_sleeping(philo);
		keep_thinking(philo);
	}
	return (NULL);
}

/**
 * @brief Responsible to keep the philo sleeping.
 * Log the status and sleep the thread
 * @param philo
 */
static void keep_sleeping(t_philo *philo)
{
	log_status(philo, S_SLEEPING);
	thread_sleep(philo->table, philo->table->time_to_sleep);
}

/**
 * @brief Responsible to Eating process.
 * This will: 1) Lock forks, 2) Log this action, 3) Log eating routine.
 * 4) Update last meal, 5) Sleep until time to eat, 6)Update eat property
 * @param philo Philo property
 */
static void keep_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_lock[philo->fork[F_LEFT]]);
	log_status(philo, S_LEFT_FORK);
	pthread_mutex_lock(&philo->table->fork_lock[philo->fork[F_RIGHT]]);
	log_status(philo, S_RIGHT_FORK);

	log_status(philo, S_EATING);

	set_last_meal_prop(philo, datetime_now());

	thread_sleep(philo->table, philo->table->time_to_eat);

	if(has_dinner_finish(philo->table) == false)
		increment_times_eat_prop(philo);

	pthread_mutex_unlock(&philo->table->fork_lock[philo->fork[F_RIGHT]]);
	pthread_mutex_unlock(&philo->table->fork_lock[philo->fork[F_LEFT]]);
}

// TODO: Classe mutex?
bool	has_dinner_finish(t_table *table)
{
	bool result;

	result = false;
	pthread_mutex_lock(&table->dinner_end_lock);
	if (table->dinner_end == true)
		result = true;
	pthread_mutex_unlock(&table->dinner_end_lock);
	return (result);
}

static void	keep_thinking(t_philo *philo)
{
	time_t time_thinking;

	time_thinking = 500; // TODO: Rever isso.

	log_status(philo, S_THINKING);
	thread_sleep(philo->table, time_thinking);
}


/**
 * @brief Handle single Philo. Grab the fork and wait until die.
 * Philos are not allowed to eat with just one fork
 * @param philo
 */
static void *lonely_philo(t_philo *philo)
{
	log_status(philo, S_LEFT_FORK);
	thread_sleep(philo->table, philo->table->time_to_die);
	log_status(philo, S_DEAD);

	return (NULL);
}

void thread_sleep(t_table *table, time_t duration)
{
	time_t time_wake_up;

	time_wake_up = datetime_now() + duration;

	while (datetime_now() < time_wake_up)
	{
		usleep(100);
	}
}
