/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:33:09 by jrheeder          #+#    #+#             */
/*   Updated: 2019/09/16 14:00:20 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colony.h"
#include "../libft/libft.h"
#include <stdio.h>

char	*get_room_name(char *room)
{
	char	*retRoomName;
	char	**roomName;

	roomName = ft_strsplit(room, ' ');
//	printf("room = %s\nroomName[0] = %s\n", room, roomName[0]);
	retRoomName = ft_strdup(roomName[0]);
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
	int k;
	int linkAmnt;
	char *names;
	char *curLink;
	char **linkNames;

	i = 0;
	j = 0;
	k = 0;
	linkAmnt = 0;
	while (data->links[linkAmnt])
		linkAmnt++;
printf("linkAmnt == %d\n", linkAmnt);
	names = NULL;
	curLink = NULL;
	// while (data->rooms[j])
	// {
	// 	names[j] = get_room_name(data->rooms[j]);
	// 	j++;
	// }
	while (i < linkAmnt)
	{
 printf("data->links[%d] == %s\n", i, data->links[i]);
		curLink = ft_strdup(data->links[i]);
		linkNames = ft_strsplit(curLink, '-');
		j = 0;
		while (data->rooms[j])
		{
printf("1: linkNames[0] = %s\n", linkNames[0]);
			names = get_room_name(data->rooms[j]);
printf("1: names = %s\n", names);
			if (ft_strequ(names, linkNames[0]))
			{
				k = 0;
				while (data->rooms[k])
				{
					names = get_room_name(data->rooms[k]);
					printf("2: linkNames[1] = %s\n", linkNames[1]);
					printf("2: names = %s\n", names);
					if (ft_strequ(names, linkNames[1]))
						break;
					k++;
					if (!data->rooms[k])
 						return (0);
				}
				break;
			}
			j++;
			if (!data->rooms[j])
 				return (0);
		}
		i++;
// 		j = 0;
// 		while (data->rooms[j])
// 		{
// //printf("linkNames[0] = %s\nlinkNames[1] = %s\n", linkNames[0], linkNames[1]);
// 			names = get_room_name(data->rooms[j]);
// //printf("names = %s\n", names);
// 			if (ft_strequ(names, linkNames[1]))
// 				break;
// 			j++;
// 			if (!data->rooms[j])
//  				return (0);
//		free(curLink);
	}
	return (1);
}

void		validate(t_log *data)
{
printf("checking links\n");
	if (!(check_links(data)))
		LINKS_ERROR;
printf("links fine\n");
printf("checking names\n");
	if (!(check_name(data)))
		NAME_ERROR;
printf("names fine\n");
printf("checking XY\n");
	if (!(check_name_XY(data)))
		XY_ERROR;
printf("XY fine\n");
}
