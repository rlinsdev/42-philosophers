/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:52:31 by rlins             #+#    #+#             */
/*   Updated: 2023/01/31 17:31:31 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*free_table(t_table *table)
{
	int	i;

	if (!table)
		return (NULL);
	if (table->philo)
	{
		i = 0;
		while (i < table->nbr_philo)
		{
			free(table->philo[i]);
			i++;
		}
		free(table->philo);
	}
	free(table);
	return (NULL);
}
