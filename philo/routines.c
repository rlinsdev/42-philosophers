/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:22:12 by rlins             #+#    #+#             */
/*   Updated: 2023/01/31 13:38:10 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void *lonely_philo(t_philo *philo);

void *dinning_routines(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;

	if (philo->table->nbr_philo == 1)
		return (lonely_philo(philo));

	return (NULL);
}

/**
 * @brief Handle single Philo. Grab the fork and wait until die
 * @param philo
 */
static void *lonely_philo(t_philo *philo)
{
	// TODO: Colocar isso na primeira execução, não só no 1 philo
	if (PRETTY == 1)
		printf("%s \t%s\t%s\n","[Milliseconds]", "[Philo Number]", "[Action]");
	log_status(philo, S_FORK);
	//TODO : Waiting...
	log_status(philo, S_DEAD);

	return (NULL);
}

