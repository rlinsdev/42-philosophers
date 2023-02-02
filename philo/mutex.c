/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:34:59 by rlins             #+#    #+#             */
/*   Updated: 2023/02/02 10:14:52 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_last_meal_prop(t_philo *philo, time_t value)
{
	pthread_mutex_lock(&philo->last_meal_lock);
	philo->last_meal = philo->table->start_dinning;
	pthread_mutex_unlock(&philo->last_meal_lock);
}

void	set_dinner_end_prop(t_table *table, bool value)
{
	pthread_mutex_lock(&table->dinner_end_lock);
	table->dinner_end = value;
	pthread_mutex_unlock(&table->dinner_end_lock);
}

void	increment_times_eat_prop(t_philo *philo)
{
	pthread_mutex_lock(&philo->nbr_meals_done_lock);
	philo->nbr_meals_done++;
	pthread_mutex_unlock(&philo->nbr_meals_done_lock);
}
