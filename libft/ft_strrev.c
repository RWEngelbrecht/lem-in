/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 00:34:35 by jrheeder          #+#    #+#             */
/*   Updated: 2020/05/29 09:18:30 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		len;

	i = 0;
	len = (int)ft_strlen(str);
	while (len - 1 > i)
	{
		tmp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = tmp;
		len--;
		i++;
	}
	return (str);
}
