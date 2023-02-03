/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:04:02 by rlins             #+#    #+#             */
/*   Updated: 2023/02/03 09:18:55 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void end_dinning(t_table *table);
static bool start_dinning(t_table *table);

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
	if (start_dinning(table) == false)
		return (EXIT_FAILURE);
	end_dinning(table);
	// free_table(table);
	return (EXIT_SUCCESS);
}

static void end_dinning(t_table *table)
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
 * @brief This method will start the dinning of philosophers.
 * Will start the threads to
 *
 * @param table
 */
static bool start_dinning(t_table *table)
{
	int i;
	header_pretty();
	i = 0;
	while (i < table->nbr_philo)
	{
		if (pthread_create(&table->philo[i]->thread_philo, NULL,
				&dinning_routines, table->philo[i]) != 0)
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
