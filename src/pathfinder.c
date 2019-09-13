/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:34:57 by rengelbr          #+#    #+#             */
/*   Updated: 2019/09/13 11:33:20 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colony.h"
#include "../libft/libft.h"
#include <stdio.h>
//finds every link in all_links that references name
char	**find_linked_rooms(char *name, char **all_links)
{
	unsigned int	name_len;
	unsigned int	i;
	unsigned int	j;
	char			**connected;

	name_len = ft_strlen(name);
	i = 0;
	j = 0;
	connected = (char**)malloc(sizeof(char*));
	while (all_links[i])
	{
		if (ft_strnstr(all_links[i], name, ft_strlen(all_links[i])))
		{
			connected[j] = all_links[i];
			j++;
		}
		i++;
	}
	return (connected);
}

//Takes current maze, name of room to add and 2D array with refs to all
//rooms it links to as well as type (i.e. start(0), end(2) or normal(1))
// t_room	*new_room(t_room *maze, char *name, char **links, unsigned int type)
// {

// }

void	map_links(t_log *data)
{
	t_room *maze;
	int i;
	char **cur_links;
	char *room_name;
	char *start_room;
	char *end_room;

	maze = malloc(sizeof(t_room));
	i = 0;
	cur_links = (char**)malloc(sizeof(sizeof(char*)));
	start_room = data->rooms[data->start_index];
	end_room = data->rooms[data->end_index];
	while (data->rooms[i])
	{
		room_name = get_room_name(data->rooms[i]);
		cur_links = find_linked_rooms(room_name, data->links);
		// if (i == data->start_index)
		// 	maze = new_room(maze, data->rooms[i], cur_links, 0);
		// else if (i == data->end_index)
		// 	maze = new_room(maze, data->rooms[i], cur_links, 2);
		// else
		// 	maze = new_room(maze, data->rooms[i], cur_links, 1);
		i++;
	}
	i = 0;
	while (cur_links[i])
	{
		printf("cur_links[%d] == %s\n", i, cur_links[i]);
		i++;
	}
}
