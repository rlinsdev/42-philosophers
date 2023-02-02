/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_finish.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:59:16 by rlins             #+#    #+#             */
/*   Updated: 2023/02/02 15:39:53 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool dinner_finished_reached(t_table *table);

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
 * @brief Check by Meal time if the philo must be killed
 * @param philo
 * @return true
 * @return false
 */
static bool	kill_philo(t_philo *philo)
{
	time_t	actual_time;

	actual_time = datetime_now();
	if (actual_time - philo->last_meal >= philo->table->time_must_eat)
	{
		set_dinner_end_prop(philo->table, true);
		log_status(philo, S_DEAD);
	}
	return (false);
}

/**
 * @brief Will return true when some philo died or if they eat enough.
 * @param table
 * @return true
 * @return false
 */
bool dinner_finished_reached(t_table *table)
{
	int		i;
	bool	eat_enough;

	i = 0;
	while (i < table->nbr_philo)
	{
		if (kill_philo(table->philo[i]))
			return (true);
		if (table->time_must_eat != -1)
			if (table->philo[i]->nbr_meals_done < table->time_must_eat)
				eat_enough = true;
		i++;
	}
	if (table->time_must_eat != -1 && eat_enough == true)
	{
		set_dinner_end_prop(table, true);
		return (true);
	}
	return (false);
}
