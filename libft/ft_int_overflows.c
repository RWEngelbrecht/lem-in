/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_overflows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 20:11:28 by jrheeder          #+#    #+#             */
/*   Updated: 2019/08/26 15:57:27 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_int_overflows(const char *str)
{
	long	res;
	int		neg;

	res = 0;
	neg = 1;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		(*str == '-') ? (neg = -1) : 1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = (res * 10) + (*str - '0');
		if (neg == 1)
			if (res > 2147483647)
				return (1);
		str++;
	}
	res *= neg;
	if (res < -2147483648)
		return (1);
	return (0);
}
