/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:16:49 by rlins             #+#    #+#             */
/*   Updated: 2023/02/02 17:27:28 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void sort_fork_by_philo(t_philo *philo);
static t_philo **init_philo(t_table *table);
static bool init_mutex(t_table *table);
static pthread_mutex_t	*init_forks(t_table *table);

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
	table->philo = malloc(sizeof(t_philo) * table->nbr_philo);
	init_philo(table);
	if (table->philo == NULL)
		return (NULL);
	if(init_mutex(table) == false)
		return (NULL);
	return (table);
}

/**
 * @brief TODO: Precisa rever este método todo. só consegui fazer funcionar
 * dando malloc antes de chamar o método e depois. Precisará dar free nestes cara do jeit oq está.
 *
 * @param table
 */
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
		if (pthread_mutex_init(&philos[i]->last_meal_lock, 0) != 0)
			return (error_msg_null(ERR_MUTEX, NULL));
		if (pthread_mutex_init(&philos[i]->nbr_meals_done_lock, 0) != 0)
			return (error_msg_null(ERR_MUTEX, NULL));
		philos[i]->table = table;
		philos[i]->id = i;
		philos[i]->nbr_meals_done = 0;

		sort_fork_by_philo(philos[i]);
		i++;
	}

	table->philo = philos;
	return (philos);
}

static pthread_mutex_t	*init_forks(t_table *table)
{
	pthread_mutex_t	*forks;
	long			i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * table->nbr_philo);
	if (!forks)
		return (error_msg_null(ERR_MALLOC, NULL));
	while (i < table->nbr_philo)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (error_msg_null(ERR_MUTEX, NULL));
		i++;
	}
	return (forks);
}

/**
 * @brief Initialize Mutex used in project
 * @param tablet tbl structure
 * @return true - success
 * @return false - error
 */
static bool init_mutex(t_table *table)
{
	table->fork_lock = init_forks(table);
	if (!table->fork_lock)
		return (false);
	if (pthread_mutex_init(&table->dinner_end_lock, 0) != 0)
		return (error_msg_null(ERR_MUTEX, NULL));

	// TODO: DEixei outras inicializações perdidas no código. Adicionar aqui.
	return (true);
}

/**
 * @brief Will define what fork the philo can take.
 * Was made this way to avoid dead lock.
 * @param philo
 */
static void sort_fork_by_philo(t_philo *philo)
{
	philo->fork[0] = philo->id;
	if (philo->table->nbr_philo > 1)
	{
		philo->fork[1] = (philo->id + 1) % philo->table->nbr_philo;
		if (philo->id % 2 != 0)
		{
			philo->fork[0] = (philo->id + 1) % philo->table->nbr_philo;
			philo->fork[1] = philo->id;
		}
	}
}
