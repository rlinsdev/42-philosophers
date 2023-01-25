/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:16:49 by rlins             #+#    #+#             */
/*   Updated: 2023/01/25 10:11:54 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void grab_forks(t_table *table, t_philo *philo);
static t_philo **init_philo(t_table *table);

t_table	*init_table(int argc, char **argv, t_table *table)
{
	// TODO: Must Freelá este cara.
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
	table->table_stop = false;
	table->philo = init_philo(table);
	return (table);
}

static t_philo **init_philo(t_table *table)
{
	t_philo	**philos;
	long	i;

	i = 0;
	// TODO: Must Freelá este cara.
	philos = malloc(sizeof(t_philo) * table->nbr_philo);
	if (philos == NULL)
		return (error_msg_null(ERR_MALLOC, NULL));

	while (i < table->nbr_philo)
	{
		philos[i] = malloc(sizeof(t_philo));
		// TODO: Must Freelá este cara.
		if (philos[i] == NULL)
			return (error_msg_null(ERR_MALLOC, NULL));
		philos[i]->id = i;
		grab_forks(table, philos[i]);
		i++;
	}
	return (philos);
}

/**
 * @brief
 *
 * @param table
 * @param philo
 */
static void grab_forks(t_table *table, t_philo *philo)
{

}
