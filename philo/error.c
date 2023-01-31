/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:01:03 by rlins             #+#    #+#             */
/*   Updated: 2023/01/31 17:01:20 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*error_msg_null(char *str, t_table *table)
{
	if (table)
	{
		free_table(table);
	}
	printf("%s", str);
	return (NULL);
}
