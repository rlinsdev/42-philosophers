/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:07:02 by rlins             #+#    #+#             */
/*   Updated: 2023/02/06 15:03:11 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*parse_status(t_state status);
static char	*parse_format_pretty(t_state status);

void	log_status(t_philo *philo, t_state status)
{
	pthread_mutex_lock(&philo->table->log_lock);
	if (has_dinner_finish(philo->table) == true)
	{
		pthread_mutex_unlock(&philo->table->log_lock);
		return ;
	}
	if (PRETTY == 1)
	{
		printf(parse_format_pretty(status), get_time_ms(
				philo->table->start_dinning), philo->id + 1,
			parse_status(status));
	}
	else
		printf("%i %ld %s\n", get_time_ms(philo->table->start_dinning),
			philo->id + 1, parse_status(status));
	pthread_mutex_unlock(&philo->table->log_lock);
}

/**
 * @brief
 * 34m - blue	Thinking
 * 33m - bow	Sleeping
 * 35m - Purple Eating
 * 31m - Red - 	Dead
 * 36m - Cyan	Fork
 * @param status
 * @return char*
 */
static char	*parse_format_pretty(t_state status)
{
	if (status == S_EATING)
		return ("\e[35m%i \t\t%ld\t\t %s\e[0m\n");
	else if (status == S_LEFT_FORK)
		return ("\e[36m%i \t\t%ld\t\t %s\e[0m - [Left ]\n");
	else if (status == S_RIGHT_FORK)
		return ("\e[36m%i \t\t%ld\t\t %s\e[0m - [Right]\n");
	else if (status == S_SLEEPING)
		return ("\e[33m%i \t\t%ld\t\t %s\e[0m\n");
	else if (status == S_THINKING)
		return ("\e[34m%i \t\t%ld\t\t %s\e[0m\n");
	else if (status == S_DEAD)
		return ("\e[31m%i \t\t%ld\t\t %s\e[0m\n");
	else
		return ("%i \t%ld\t %s\n");
}

/**
 * @brief Translate the state from enum, to this description
 * @param status
 * @return char*
 */
static char	*parse_status(t_state status)
{
	if (status == S_EATING)
		return ("is eating");
	else if (status == S_LEFT_FORK || status == S_RIGHT_FORK)
		return ("has taken a fork");
	else if (status == S_SLEEPING)
		return ("is sleeping");
	else if (status == S_THINKING)
		return ("is thinking");
	else if (status == S_DEAD)
		return ("died");
	else
		return ("");
}

void	header_pretty(void)
{
	if (PRETTY == 1)
		printf("\n\e[32m%s \t%s\t%s\e[0m\n", "[Milliseconds]", "[Philo Number]",
			"[Action]");
}
