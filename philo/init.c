/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:16:49 by rlins             #+#    #+#             */
/*   Updated: 2023/01/25 08:10:47 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static long	get_param(char *value);
static t_philo **init_philo(t_dinner *dinner);

t_dinner	*init_dinner(int argc, char **argv, t_dinner *dinner)
{
	// TODO: Must Freelá este cara.
	dinner = malloc(sizeof(dinner));
	if (!dinner)
		return (error_msg_null(ERR_MALLOC, NULL));
	dinner->nbr_philo = ft_ato_long(argv[1]);
	dinner->time_to_die = ft_ato_long(argv[2]);
	dinner->time_to_eat = ft_ato_long(argv[3]);
	dinner->time_to_sleep = ft_ato_long(argv[4]);
	dinner->time_must_eat = -1;
	if (argc == 6)
		dinner->time_must_eat = ft_ato_long(argv[5]);
	dinner->dinner_stop = false;
	dinner->philo = init_philo(dinner);
	return (dinner);
}

static t_philo **init_philo(t_dinner *dinner)
{
	t_philo	**philos;
	long	i;

	i = 0;
	// TODO: Must Freelá este cara.
	philos = malloc(sizeof(t_philo) * dinner->nbr_philo);
	if (philos == NULL)
		return (error_msg_null(ERR_MALLOC, NULL));

	while (i < dinner->nbr_philo)
	{
		philos[i] = malloc(sizeof(t_philo));
		// TODO: Must Freelá este cara.
		if (philos[i] == NULL)
			return (error_msg_null(ERR_MALLOC, NULL));
		philos[i]->id = i;
		i++;
	}

	return (philos);
}
