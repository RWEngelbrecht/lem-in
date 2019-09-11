/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:28:51 by jrheeder          #+#    #+#             */
/*   Updated: 2019/09/11 08:11:14 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/colony.h"
#include <stdio.h>
int main()
{
	char *line;
	t_log *ret;
	int i = 0;
	int j = 0;

	line = NULL;
	ret = NULL;
	ret = read_input(&line);

	printf("ant amnt = %d\nstart_line = %d\nend_line = %d\n", ret->ant_amnt, ret->start_line, ret->end_line);
	while (ret->rooms[i])
	{
		printf("rooms[%d] = %s\n", i, ret->rooms[i]);
		i++;
	}
	while (ret->links[j])
	{
		printf("links[%d] = %s\n", j, ret->links[j]);
		j++;
	}
}
