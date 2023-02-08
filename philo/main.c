/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:04:02 by rlins             #+#    #+#             */
/*   Updated: 2023/02/08 10:51:03 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	end_dining(t_table *table);
static bool	start_dining(t_table *table);

/**
 * @brief Main Class of program
 * @param argc Arguments Count
 * @param argv Arguments Vector
 * @return int
 */
int	main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	if (is_valid_args(argc, argv) == false)
		return (EXIT_FAILURE);
	table = init_table(argc, argv);
	if (!table)
		return (EXIT_FAILURE);
	if (start_dining(table) == false)
		return (EXIT_FAILURE);
	end_dining(table);
	return (EXIT_SUCCESS);
}

/**
 * @brief Responsible to finish the philo dining.
 * Will join all threads and free all objects
 * @param table Table structure
 */
static void	end_dining(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_join(table->philo[i]->thread_philo, NULL);
		i++;
	}
	if (table->nbr_philo > 1)
		pthread_join(table->thread_table, NULL);
	free_table(table);
}

/**
 * @brief This method will start the dining of philosophers.
 * Will start the threads (Nbr threads is the same nbr philo)
 * Will start the thread to finish the dinner.
 * @param table
 */
static bool	start_dining(t_table *table)
{
	int	i;

	header_pretty();
	i = 0;
	while (i < table->nbr_philo)
	{
		if (pthread_create(&table->philo[i]->thread_philo, NULL,
				&dining_routines, table->philo[i]) != 0)
			return (error_msg_null(ERR_THREAD, table));
		i++;
	}
	if (table->nbr_philo > 1)
	{
		if (pthread_create(&table->thread_table, NULL, &finish_routines_reached,
				table) != 0)
			return (error_msg_null(ERR_THREAD, table));
	}
	return (true);
}
