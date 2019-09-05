/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 06:02:51 by jrheeder          #+#    #+#             */
/*   Updated: 2019/07/22 12:56:00 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = ft_strnew(len);
	if (!str || !s)
		return (NULL);
	i = 0;
	s = s + start;
	if (s)
	{
		while (i < len)
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	else
		return (0);
	return (str);
}
