/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:02:00 by rlins             #+#    #+#             */
/*   Updated: 2023/01/23 21:03:05 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

enum state {
	eating,
	thinking,
	sleeping,
	hungry,
};

# include <stdio.h> // Printf
# include <stdlib.h> // Malloc
# include <pthread.h> //pthread_*, mutex
# include <unistd.h> // Sleep
# include <semaphore.h> // semaphore
# include <stdbool.h> //boolean
# include <limits.h> // long_max

/******************************************************************************/
/*Begin - Initialization*/
/******************************************************************************/
/**
 * @brief First method in project.
 * @param argc Arguments count
 * @param argv Arguments Vector
 * @param envp Environment pointer variable
 * @return int
 */
int	init(int argc, char **argv, char **envp);
int	race_cond();
int	deadlock();
int	deadlock2();
int	func_semaphore(void);
void circle(void);
int	ft_ato_long(const char *str, bool *error);
int	comb1();

//eat
//release_forks
//sleep
//think

/******************************************************************************/
/*End - Initialization*/
/******************************************************************************/


#endif
