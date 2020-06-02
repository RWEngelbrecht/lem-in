/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 00:34:14 by jrheeder          #+#    #+#             */
/*   Updated: 2019/07/22 12:53:57 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n)
	{
		if ((unsigned char)*s1 - (unsigned char)*s2 < 0)
			return (-1);
		if ((unsigned char)*s1 - (unsigned char)*s2 > 0)
			return (1);
	}
	return (0);
}
