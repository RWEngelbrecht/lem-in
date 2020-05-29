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
  int i;
  int j;
  char temp;

  i = ft_strlen(str) - 1;
  j = 0;
  while (str[i])
  {
    write(1, "a", 1);
    temp = str[j];
    str[j] = str[i];
    str[i] = temp;
    i--;
    j++;
  }
  ft_putstr("\n");
  ft_putstr(str);
  ft_putstr("\n");
  return (str);
}
