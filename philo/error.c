/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:01:03 by rlins             #+#    #+#             */
/*   Updated: 2023/01/24 12:23:36 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*error_msg_null(char *str, t_dinner *dinner)
{
	// TODO
	// if (dinner)
	// {
	// 	// free_dinner(dinner)
	// }
	printf("%s", str);
	return (NULL);
}
