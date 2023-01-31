/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:07:02 by rlins             #+#    #+#             */
/*   Updated: 2023/01/31 11:56:08 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char *parse_status(t_state status);

void log_status(t_philo *philo, t_state status)
{
	printf("%i %ld %s\n", get_time_ms(philo->table->start_dinning), philo->id,
		parse_status(status));
}

/**
 * @brief Translate the state from enum, to this description
 * @param status
 * @return char*
 */
static char *parse_status(t_state status)
{
	if (status == S_EATING)
		return "is eating";
	else if (status == S_FORK)
		return "has taken a fork";
	else if (status == S_SLEEPING)
		return "is sleeping";
	else if (status == S_THINKING)
		return "is thinking";
	else if (status == S_DEAD)
		return "died";
}

