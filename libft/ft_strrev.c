/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 19:15:49 by rigardte          #+#    #+#             */
/*   Updated: 2020/05/26 13:48:26 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	size_t	n;
	size_t	size;
	size_t	half;
	size_t	size2;
	char	str;

	n = 0;
	size = ft_strlen(s);
	half = size / 2;
	if (s)
	{
		while (n < half)
		{
			size2 = size - n - 1;
			str = s[n];
			s[n] = s[size2];
			s[size2] = str;
			n++;
		}
	}
	return (s);
}
