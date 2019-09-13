/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:33:09 by jrheeder          #+#    #+#             */
/*   Updated: 2019/09/13 10:15:43 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colony.h"
#include "../libft/libft.h"
#include <stdio.h>

char	*get_room_name(char *room)
{
	char *retRoomName;
	char**roomName;

	roomName = ft_strsplit(room, ' ');
	retRoomName = roomName[0];
	return (retRoomName);
}

int     check_name(t_log *data) //Check if rooms start with 'L' or '#'
{
    // iterators
    int i;
    int j;

    i = 0;

    /*if (phase != 1)
        return (0);*/
    while (data->rooms[i])
    {
        j = i + 1;
        while (data->rooms[j])
        {
            if (ft_strequ(data->rooms[i], data->rooms[j]))
            {
                return (0); // found duplicate.
            }
            j++;
        }
        i++;
    }
    return (1); // no duplicates found.
    // need to check for duplicate names
    // need to check for duplicate x and y cords
    // need to check for valid phases

}

int     check_name_XY(t_log *data)
{
	int i;
	int j;
	char **roomName;
	char **roomNameComp;

	roomNameComp = NULL;
	roomName = NULL;
	i = 0;
	j = 1;
	while(data->rooms[i])
	{
		roomName = ft_strsplit(data->rooms[i], ' ');
		while (data->rooms[j])
		{
			roomNameComp = ft_strsplit(data->rooms[j], ' ');
			if (ft_strequ(roomName[1], roomNameComp[1])
					&& ft_strequ(roomName[2], roomNameComp[2]))
				return (0);
			j++;
		}
		i++;
    }
    i = 0;
    return (1);
}

//Checks if all links use valid room names, exits with Error if not.
int		check_links(t_log *data)
{
	int i;
	int j;
	char **names;
	char **curLink;

	i = 0;
	j = 0;
	names = (char**)malloc(sizeof(char*));
	curLink = NULL;
	while (data->rooms[j])
	{
		names[j] = get_room_name(data->rooms[j]);
		j++;
	}
	while (data->links[i])
	{
		curLink = ft_strsplit(data->links[i], '-');
		j = 0;
		while (names[j])
		{
			if (ft_strequ(curLink[0], names[j]))
				break;
			j++;
			if (!names[j] || ft_strequ(curLink[0], curLink[1]))
				return (0);
		}
		j = 0;
		while (names[j])
		{
			if (ft_strequ(curLink[1], names[j]))
				break;
			j++;
			if (!names[j] || ft_strequ(curLink[0], curLink[1]))
				return (0);
		}
		i++;
	}
	return (1);
}

void		validate(t_log **data)
{
	if (!(check_links(*data)))
		ERROR;
	if (!(check_name(*data)))
		ERROR;
	if (!(check_name_XY(*data)))
		ERROR;
}
