/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:33:09 by jrheeder          #+#    #+#             */
/*   Updated: 2019/09/12 11:09:06 by rengelbr         ###   ########.fr       */
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

int     check_name(t_log *data/*, int phase*/)
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
				ERROR;
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
	int k;
	char **names;
	char **curLink;

	i = 0;
	j = 0;
	names = (char**)malloc(sizeof(char*));
	curLink = NULL;
	while (data->rooms[k])
	{
		names[k] = get_room_name(data->rooms[k]);
		k++;
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
			if (!names[j])
				ERROR;
		}
		j = 0;
		while (names[j])
		{
			if (ft_strequ(curLink[1], names[k]))
				break;
			k++;
			if (!names[k])
				ERROR;
		}
		i++;
	}
	return (1);
}
