/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:16:49 by rlins             #+#    #+#             */
/*   Updated: 2023/02/01 09:12:49 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void grab_forks(t_philo *philo);
static t_philo **init_philo(t_table *table);
static bool init_mutex(t_table *table);

t_table	*init_table(int argc, char **argv)
{
	t_table *table;
	table = malloc(sizeof(table));
	if (!table)
		return (error_msg_null(ERR_MALLOC, NULL));
	table->nbr_philo = ft_ato_long(argv[1]);
	table->time_to_die = ft_ato_long(argv[2]);
	table->time_to_eat = ft_ato_long(argv[3]);
	table->time_to_sleep = ft_ato_long(argv[4]);
	table->time_must_eat = -1;
	if (argc == 6)
		table->time_must_eat = ft_ato_long(argv[5]);
	table->dinner_end = false;
	table->start_dinning = datetime_now();
	table->philo = init_philo(table);
	if (table->philo == NULL)
		return (NULL);
	if(init_mutex(table) == false)
		return (NULL);
	return (table);
}

static t_philo **init_philo(t_table *table)
{
	t_philo	**philos;
	long	i;

	i = 0;
	philos = malloc(sizeof(t_philo) * table->nbr_philo);
	if (philos == NULL)
		return (error_msg_null(ERR_MALLOC, NULL));

	while (i < table->nbr_philo)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (philos[i] == NULL)
			return (error_msg_null(ERR_MALLOC, NULL));
		philos[i]->id = i;
		philos[i]->table = table;
		philos[i]->nbr_meals_done = 0;

		if (pthread_mutex_init(&philos[i]->last_meal_lock, 0) != 0)
			return (error_msg_null(ERR_MUTEX, NULL));

		grab_forks(philos[i]);
		i++;
	}
	return (philos);
}

/**
 * @brief Initialize Mutex used in project
 * @param tablet tbl structure
 * @return true - success
 * @return false - error
 */
static bool init_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->dinner_end_lock, 0) != 0)
		return (error_msg_null(ERR_MUTEX, NULL));

	return (true);
}

/**
 * @brief
 * TODO: Get it better.
 * @param philo
 */
static void grab_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		philo->r_fork = philo->id;
		philo->l_fork = philo->id  +1;
	}
}
