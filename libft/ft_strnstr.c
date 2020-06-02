/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 00:34:27 by jrheeder          #+#    #+#             */
/*   Updated: 2019/07/22 12:54:51 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ndl, size_t len)
{
	size_t	nd_len;
	size_t	i;
	int		last;

	if (!(*ndl))
		return ((char *)hay);
	if (!(*hay))
		return (NULL);
	nd_len = ft_strlen(ndl);
	i = 0;
	last = 1;
	while (nd_len <= len && hay[i] != '\0' &&
			(last = ft_strncmp(&hay[i], ndl, nd_len)))
	{
		len--;
		i++;
	}
	if (last == 0)
		return ((char*)&hay[i]);
	else
		return (NULL);
}
