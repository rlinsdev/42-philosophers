/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:20:01 by rlins             #+#    #+#             */
/*   Updated: 2023/02/02 17:17:32 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int datetime_now()
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return time.tv_sec * 1000 + time.tv_usec / 1000;
}

int	get_time_ms(int start_dinning)
{
	return (datetime_now() - start_dinning);
}

void thread_sleep(t_table *table, time_t duration)
{
	time_t time_wake_up;

	time_wake_up = datetime_now() + duration;
	while (datetime_now() < time_wake_up)
	{
		usleep(100);
	}
}
