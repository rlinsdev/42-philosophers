/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:04:02 by rlins             #+#    #+#             */
/*   Updated: 2023/02/02 10:35:43 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void end_dinning(t_table *table);
static void start_dinning(t_table *table);

/**
 * @brief Main Class of program
 * @param argc Arguments Count
 * @param argv Arguments Vector
 * @return int
 */
int	main(int argc, char **argv)
{
	// printf("%d\n", datetime_now());
	// // wait 1 second
	// sleep(1);
	// printf("%d\n", datetime_now());


	// return (0);

	t_table	*table;

	table = NULL;
	if (is_valid_args(argc, argv) == false)
		return (EXIT_FAILURE);
	table = init_table(argc, argv);
	if (!table)
		return (EXIT_FAILURE);
	start_dinning(table);
	end_dinning(table);
	free_table(table);
	return (EXIT_SUCCESS);
}

static void end_dinning(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_join(table->philo[i]->thread, NULL);
		i++;
	}
}

/**
 * @brief TODO: Colocar na classe de output
 *
 * @param philo
 */
static void header_pretty()
{
	if (PRETTY == 1)
		printf("\n\e[32m%s \t%s\t%s\e[0m\n","[Milliseconds]", "[Philo Number]", "[Action]");
}

static void start_dinning(t_table *table)
{
	int i;
	header_pretty();
	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_create(&table->philo[i]->thread, NULL, &dinning_routines,
			 table->philo[i]);
		i++;
	}
}
