/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 07:23:10 by rengelbr          #+#    #+#             */
/*   Updated: 2019/09/09 18:22:11 by rengelbr         ###   ########.fr       */
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


int		is_command(char *line)
{
	if (ft_strnequ(line, "##", 2))
		return (1);
	return (0);
}

// int		is_room(char *line)
// {
// 	if (ft_wordcount(line, ' ') == 3)
// 		return (1);
// 	return (0);
// }

// int		is_link(char *line)
// {
// 	char *str;

// 	str = line;
// 	while (*str)
// 	{
// 		if (*str == '-')
// 			return (1);
// 		str++;
// 	}
// 	return (0);
// }

char	*get_room_name(char *line)
{
	char *retRoomName;

	retRoomName = NULL;
	while (get_next_line(0, &line))
	{
		char** roomName;
		if (ft_wordcount(line, ' ') == 3)
		{
			roomName = ft_strsplit(line, ' ');
			retRoomName = roomName[0];
		}
		printf("%s\n", retRoomName);
	}
	return (retRoomName);
}



int		read_input(char **line)
{
	char **rooms;
	char **links;
	int start;
	int end;
	int ants_amnt;
	int i;
	int j;

	rooms = NULL;
	links = NULL;
	start = 0;
	end = 0;
	i = 0;
	j = 0;
	get_next_line(0, line);
printf("*line == %s\n", *line);
	ants_amnt = ft_atoi(*line);
printf("ant amnt == %d\n", ants_amnt);
	while (get_next_line(0, line))
	{
		if (is_command(*line))
		{
			if (ft_strequ(*line, "##start"))
				start = 1;
			else if (ft_strequ(*line, "##end"))
				end = 1;
printf("start == %d\nend == %d\n", start, end);
		}
		//does not work yet
//		else if (is_room(*line))
//			rooms[i] = *line;
//		else if (is_link(*line))
//			links[j] = *line;
printf("rooms == %s\nlinks == %s\n", *rooms, *links);
	}
	//room_populate()
	return (0);
}

// t_room	*room_populate(char **line)
// {
// 	t_room	*room;

// 	if (!(t_room*)malloc(sizeof(t_room)))
// 		return (NULL);

// }
