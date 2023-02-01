/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:16:49 by rlins             #+#    #+#             */
/*   Updated: 2023/02/01 12:38:18 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void sort_fork_by_philo(t_philo *philo);
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

		sort_fork_by_philo(philos[i]);
		i++;
	}

	// Debug Fork
	// i = 0;
	// while (i < table->nbr_philo)
	// {
	// 	int value = (philos[i]->id + 1) % philos[i]->table->nbr_philo;
	// 	printf("Calc: (%li + 1) %% %li = %i\n", philos[i]->id, philos[i]->table->nbr_philo, value);
	// 	printf("Philo:[%li]. Fork[0]:[%i] \n", (i + 1), philos[i]->fork[0]);
	// 	printf("Philo:[%li]. Fork[1]:[%i] \n", (i + 1), philos[i]->fork[1]);
	// 	i++;
	// }

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
 * @brief Will define what fork the philo can take.
 * Was made this way to avoid dead lock.
 * TODO: Get it better.
 * @param philo
 */
static void sort_fork_by_philo(t_philo *philo)
{
	philo->fork[0] = philo->id;
	if (philo->table->nbr_philo > 1)
	{
		// Quando for par...
		philo->fork[1] = (philo->id + 1) % philo->table->nbr_philo;
		if (philo->id % 2)
		{
			philo->fork[0] = (philo->id + 1) % philo->table->nbr_philo;
			philo->fork[1] = philo->id;
		}
	}
}
