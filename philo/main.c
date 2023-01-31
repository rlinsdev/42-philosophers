/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:04:02 by rlins             #+#    #+#             */
/*   Updated: 2023/01/31 10:53:58 by rlins            ###   ########.fr       */
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
	printf("%d\n", datetime_now());
	// wait 1 second
	sleep(1);
	printf("%d\n", datetime_now());


	return (0);

	t_table	*table;

	table = NULL;
	if (is_valid_args(argc, argv) == false)
		return (EXIT_FAILURE);
	table = init_table(argc, argv);
	if (!table)
		return (EXIT_FAILURE);
	start_dinning(table);
	end_dinning(table);
	return (EXIT_SUCCESS);
}

//TODO: Não permitir numeros negativos de Philo. Talvez dos oturos params tb.
// Subject: One or more philosophers sit at a round table
static void end_dinning(t_table *table)
{

}

static void start_dinning(t_table *table)
{
	int i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_create(&table->philo[i]->thread, NULL, &dinning_routines,
			 table->philo[i]);
		i++;
	}
}
