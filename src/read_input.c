/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 07:23:10 by rengelbr          #+#    #+#             */
/*   Updated: 2019/09/09 09:09:00 by rengelbr         ###   ########.fr       */
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


int		is_command(char * line)
{
	if (ft_strnequ(line, "##", 2))
		return (1);
	return (0);
}

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
	int start;
	int end;

	start = 0;
	end = 0;
	while (get_next_line(0, line))
	{
		if (is_command(*line))
			printf("this is how it works, I guess\n");

	}
	return (0);
}

// t_room	*room_populate(char **line)
// {
// 	t_room	*room;

// 	if (!(t_room*)malloc(sizeof(t_room)))
// 		return (NULL);
	
// }