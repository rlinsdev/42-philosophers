/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:22:12 by rlins             #+#    #+#             */
/*   Updated: 2023/02/01 07:54:49 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void *lonely_philo(t_philo *philo);
static void header_pretty(t_philo *philo);

void *dinning_routines(void *data)
{
	t_philo *philo;

	header_pretty(philo);
	philo = (t_philo *)data;
	if (philo->table->time_must_eat == 0)
		return (NULL);
		
	pthread_mutex_lock(&philo->last_meal_lock);
	philo->last_meal = philo->table->start_dinning;
	pthread_mutex_unlock(&philo->last_meal_lock);

	if (philo->table->nbr_philo == 1)
		return (lonely_philo(philo));

	return (NULL);
}

/**
 * @brief TODO: Colocar na classe de output
 *
 * @param philo
 */
static void header_pretty(t_philo *philo)
{
	if (PRETTY == 1)
		printf("\n\e[32m%s \t%s\t%s\e[0m\n","[Milliseconds]", "[Philo Number]", "[Action]");
}

/**
 * @brief Handle single Philo. Grab the fork and wait until die.
 * Philos are not allowed to eat with just one fork
 * @param philo
 */
static void *lonely_philo(t_philo *philo)
{	log_status(philo, S_FORK);
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
