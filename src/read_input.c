/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 07:23:10 by rengelbr          #+#    #+#             */
/*   Updated: 2019/09/16 09:29:12 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This file contains functions that read from standard output the data needed
**	to build the "ant farm". Depending on the input, these functions will call
**	functions from other files to complete the game.
*/

#include "../libft/libft.h"
#include "../includes/colony.h"

#include <stdio.h>

// Checking whether it is a command. By identifying if input has ##
int		is_command(char *line)
{
	if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
		return (1);
	return (0);
}

// Checking whether input is a room. By checking if wordcount is three.
int		is_room(char *line)
{
	if (ft_wordcount(line, ' ') == 3)
		return (1);
	return (0);
}

// Checking whether if there is a - between numbers. **Could cause negative ants to think it's a link
int		is_link(char *line)
{
	char *str;

	str = line;
	while (*str)
	{
		if (*str == '-')
			return (1);
		str++;
	}
	return (0);
}

t_log		*read_input(char **line)
{
	t_log	*data;
	int start;
	int end;
	int phase;
	int j;
	int k;

	data = (t_log*)malloc(sizeof(t_log));
	data->rooms = (char**)malloc(sizeof(char*) * 255);
	data->links = (char**)malloc(sizeof(char*) * 255);
	start = -1;
	end = -1;
	phase = 0;
	j = -1;
	k = -1;
	while (get_next_line(0, line))
	{
		if (ft_only_digits(*line) && phase == 0)
		{
			data->ant_amnt = ft_atoi(*line);
			phase = 1;
		}
		else if (ft_strequ(*line, "##start") && phase == 1)
			start = 1;
		else if (ft_strequ(*line, "##end") && phase == 1)
			end = 1;
		else if (is_room(*line))
		{
			if (phase != 1)
				ORDER_ERROR;
			data->rooms[++j] = malloc(sizeof(char) * ft_strlen(*line) + 1);
			data->rooms[j] = *line;
			if (start == 1)
			{
				data->start_index = j;
				start = 0;
			}
			else if (end == 1)
			{
				data->end_index = j;
				end = 0;
			}
		}
		else if (is_link(*line))
		{
			if (phase == 1)
				phase = 2;
			if (phase == 0 || start < 0 || end < 0)
				ORDER_ERROR;
			data->links[++k] = malloc(sizeof(char) * ft_strlen(*line) + 1);
			data->links[k] = *line;
		}
	}
	return (data);
}

// t_room	*room_populate(char **line)
// {
// 	t_room	*room;

// 	if (!(t_room*)malloc(sizeof(t_room)))
// 		return (NULL);

// }
