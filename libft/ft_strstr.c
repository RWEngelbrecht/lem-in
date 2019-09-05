/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 00:34:43 by jrheeder          #+#    #+#             */
/*   Updated: 2019/07/22 12:55:40 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *stack, const char *needle)
{
	int		i;
	int		nd_len;

	i = 0;
	nd_len = ft_strlen(needle);
	if (nd_len == 0)
		return ((char*)stack);
	while (stack[i] != '\0')
	{
		if (!(ft_strncmp((stack + i), needle, nd_len)))
			return ((char*)(stack + i));
		i++;
	}
	return (NULL);
}
