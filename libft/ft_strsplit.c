/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:30:45 by jrheeder          #+#    #+#             */
/*   Updated: 2019/07/22 12:55:25 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		wordlen(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**arr;

	if (!s || !(arr = (char **)malloc(sizeof(*arr) *
		(ft_wordcount(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_wordcount(s, c))
	{
		k = 0;
		if (!(arr[i] = ft_strnew(wordlen(&s[j], c) + 1)))
			arr[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			arr[i][k++] = s[j++];
		arr[i][k] = '\0';
	}
	arr[i] = 0;
	return (arr);
}
