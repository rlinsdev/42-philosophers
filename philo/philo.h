/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:02:00 by rlins             #+#    #+#             */
/*   Updated: 2023/01/24 10:17:11 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// TODO: Melhorar isso aqui
// TODO: Apagar pastas testes
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

# define PARAM_ERROR "Wrong arguments. Check the subject and try again.\n"

/**
 * @brief First method in project.
 * @param argc Arguments count
 * @param argv Arguments Vector
 * @return boolean
 */
bool	is_valid_args(int argc, char **argv);

/**
 * @brief Asc to Long function.
 * @param str String to be checked and transformed
 * @param error Bool variable to check error while calling
 * @return long value
 */
long	ft_ato_long(const char *str, bool *error);

/**
 * @brief Check if argument is a valid digit
 * @param c
 * @return boolean
 */
bool	ft_isdigit(int c);

#endif
