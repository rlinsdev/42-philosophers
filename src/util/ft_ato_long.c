/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:32:43 by rlins             #+#    #+#             */
/*   Updated: 2023/01/24 08:33:50 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static bool	check_out_of_range(int neg, unsigned long long num, bool *error);
static int	ft_isdigit(int c);
static int	ft_isspace(int c);

long	ft_ato_long(const char *str, bool *error)
{
	unsigned long long	num;
	int					neg;
	int					i;

	num = 0;
	neg = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		if (check_out_of_range(neg, num, error))
			break ;
		i++;
	}
	return (num * neg);
}

/**
 * @brief Check if the number is over long_max or long_min.
 * Set variable to true error if positive
 */
static bool	check_out_of_range(int neg, unsigned long long num, bool *error)
{
	if ((neg == 1 && num > LONG_MAX)
		|| (neg == -1 && num > -(unsigned long)LONG_MIN))
		*error = true;
	return (*error);
}

/**
 * @brief Check if argument is a valid digit
 * @param c
 * @return int. (0) if it's OK
 */
static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * @brief Verify spaces and spacial char
 * @param c param to verify
 * @return int. (0) if it's OK
 */
static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f')
		return (c);
	return (0);
}
