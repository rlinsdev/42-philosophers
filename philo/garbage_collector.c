/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:52:31 by rlins             #+#    #+#             */
/*   Updated: 2023/02/01 09:12:16 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_mutex(t_table *table);

void	*free_table(t_table *table)
{
	int	i;

	if (!table)
		return (NULL);

	free_mutex(table);

	if (table->philo)
	{
		i = 0;
		while (i < table->nbr_philo)
		{
			free(table->philo[i]);
			i++;
		}
		free(table->philo);
	}
	free(table);
	return (NULL);
}

static void	free_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_mutex_destroy(&table->philo[i]->last_meal_lock);
		i++;
	}
	pthread_mutex_destroy(&table->dinner_end_lock);
}
