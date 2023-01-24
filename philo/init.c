/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:16:49 by rlins             #+#    #+#             */
/*   Updated: 2023/01/24 12:22:46 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	get_param(char *value);

t_dinner *init_dinner(int argc, char **argv, t_dinner *dinner)
{
	dinner = malloc(sizeof(dinner));
	if (!dinner)
		return (error_msg_null(ERR_MALLOC, NULL));
	dinner->nbr_philo = ft_ato_long(argv[1]);

	return (dinner);
}



