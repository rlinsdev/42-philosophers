/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:04:02 by rlins             #+#    #+#             */
/*   Updated: 2023/01/23 21:03:30 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
// #include "../../include/philo.h"

/**
 * @brief Main Class of program
 * @param argc Arguments Count
 * @param argv Arguments Vector
 * @param envp Environment variables
 * @return int
 */
int	main(int argc, char **argv, char **envp)
{
	// if (argc != 5 && argc != 6)
	// {
	// 	printf("Error in arguments AAAAA\n");
	// 	exit(1);
	// }
	// else
	// {
	// 	bool error = false;
	// 	int nb_philo = ft_ato_long(argv[1], &error);
	// 	int time_die = ft_ato_long(argv[2], &error);
	// 	int time_eat = ft_ato_long(argv[3], &error);
	// 	int time_sleep = ft_ato_long(argv[4], &error);
	// 	if (argc == 6) {
	// 		int times_exit = ft_ato_long(argv[5], &error);
	// 	}
	// }

	// int result = race_cond();
	// int result = deadlock();
	// int result = func_semaphore();
	//circle();
	comb1();
	return (0);
}
