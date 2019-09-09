/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 07:23:10 by rengelbr          #+#    #+#             */
/*   Updated: 2019/09/09 14:28:13 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This file contains functions that read from standard output the data needed
**	to build the "ant farm". Depending on the input, these functions will call
**	functions from other files to complete the game.
*/

#include "libft/libft.h"


#include <stdio.h>


int		is_command(char * line)
{
	if (ft_strnequ(line, "##", 2))
		return (1);
	return (0);
}

int		read_input(char **line)
{
	int start;
	int end;

	start = 0;
	end = 0;
	while (get_next_line(0, line))
	{
		if (is_command(*line))
		{
			printf("this is how it works, I guess\n");
		}
	}
	return (0);
}
