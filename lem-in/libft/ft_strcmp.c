/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 23:52:11 by jrheeder          #+#    #+#             */
/*   Updated: 2019/07/22 12:51:24 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (((unsigned char)*s1 - (unsigned char)*s2) < 0)
		return (-1);
	if (((unsigned char)*s1 - (unsigned char)*s2) > 0)
		return (1);
	return (0);
}
