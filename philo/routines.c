/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:22:12 by rlins             #+#    #+#             */
/*   Updated: 2023/01/31 10:01:51 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void *lonely_philo(t_philo *philo);

void *dinning_routines(void *data)
{
	t_philo *philo;

	philo = (t_philo*)data;

	if (philo->table->nbr_philo == 1)
		return (lonely_philo(philo));

	return (NULL);
}

/**
 * @brief Handle single Philo.
 *
 * @param philo
 */
static void *lonely_philo(t_philo *philo)
{


	return (NULL);
}

