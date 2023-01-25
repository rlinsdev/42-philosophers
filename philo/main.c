/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:04:02 by rlins             #+#    #+#             */
/*   Updated: 2023/01/25 10:11:54 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		return (1);
	init_table(argc, argv, table);
	if (!table)
		return (EXIT_FAILURE);
	return (0);
}
