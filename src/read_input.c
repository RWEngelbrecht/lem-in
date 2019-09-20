/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 07:23:10 by rengelbr          #+#    #+#             */
/*   Updated: 2019/09/20 09:53:28 by rengelbr         ###   ########.fr       */
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

int		is_comment(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '#' && line[i + 1] != '#')
			return (1);
		i++;
	}
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

t_log		*read_input(char *line)
{
	t_log	*data;
	int start;
	int end;
	int phase;
	int j;
	int k;

	data = (t_log*)malloc(sizeof(t_log));
	data->rooms = (char**)malloc(sizeof(char*) * 2048);
	data->links = (char**)malloc(sizeof(char*) * 2048);
	start = -1;
	end = -1;
	phase = 0;
	j = -1;
	k = -1;
	while (get_next_line(0, &line))
	{
		ft_putendl(line);
		if (ft_only_digits(line) && phase == 0)
		{
			data->ant_amnt = ft_atoi(line);
			phase = 1;
		}
		else if (ft_strequ(line, "##start") && phase == 1)
			start = 1;
		else if (ft_strequ(line, "##end") && phase == 1)
			end = 1;
		else if (is_room(line))
		{
			if (phase != 1)
				ORDER_ERR;
			data->rooms[++j] = ft_strdup(line);
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
		else if (is_link(line))
		{
			if (phase == 1)
				phase = 2;
			if (phase == 0 || start < 0 || end < 0)
				ORDER_ERR;
			data->links[++k] = ft_strdup(line);
		}
		else if (is_comment(line))
		{
			ft_putstr(line);
		}
		free(line);
	}
	data->rooms[++j] = 0;
	data->links[++k] = 0;
	ft_putchar('\n');
	return (data);
}

// t_room	*room_populate(char **line)
// {
// 	t_room	*room;

// 	if (!(t_room*)malloc(sizeof(t_room)))
// 		return (NULL);

// }
