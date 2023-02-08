/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_finish.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:59:16 by rlins             #+#    #+#             */
/*   Updated: 2023/02/08 16:18:45 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	dinner_finished_reached(t_table *table);

void	*finish_routines_reached(void *data)
{
	t_table			*table;

	table = (t_table *)data;
	if (table->time_must_eat == 0)
		return (NULL);
	set_dinner_end_prop(table, false);
	while (true)
	{
		if (dinner_finished_reached(table) == true)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

/**
 * @brief Check by Meal time if the philo must be killed.
 * Must to unlock mutex, otherwise will not return the terminal
 * @param philo structure
 * @return boolean - killed or not
 */
static bool	kill_philo(t_philo *philo)
{
	if ((datetime_now() - philo->last_meal) >= philo->table->time_to_die)
	{
		log_status(philo, S_DEAD);
		set_dinner_end_prop(philo->table, true);
		pthread_mutex_unlock(&philo->general_meal_lock);
		return (true);
	}
	return (false);
}

/**
 * @brief Check if the dinner must be finished.
 * Will return true when some philo died or if they eat enough.
 * @param table structure
 * @return boolean - finished or not
 */
static bool	dinner_finished_reached(t_table *table)
{
	int		i;
	bool	eat_enough;

	i = 0;
	eat_enough = true;
	while (i < table->nbr_philo)
	{
		pthread_mutex_lock(&table->philo[i]->general_meal_lock);
		if (kill_philo(table->philo[i]) == true)
			return (true);
		if (table->time_must_eat != -1)
			if (table->philo[i]->nbr_meals_done < table->time_must_eat)
				eat_enough = false;
		pthread_mutex_unlock(&table->philo[i]->general_meal_lock);
		i++;
	}
	if (table->time_must_eat != -1 && eat_enough == true)
	{
		set_dinner_end_prop(table, true);
		return (true);
	}
	return (false);
}
