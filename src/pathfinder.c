/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:34:57 by rengelbr          #+#    #+#             */
/*   Updated: 2019/09/17 09:00:12 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colony.h"
#include "../libft/libft.h"
#include <stdio.h>
//finds every link in all_links that references name, returns it in 2d array
char	**find_linked_rooms(t_str name, t_str *all_links)
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
printf("connected[%d] = %s\nall links[%d] = %s\n", j, connected[j], i, all_links[i]);
			j++;
		}
		i++;
	}
	return (connected);
}

// void	add_room_links(t_room *maze)

int		get_coordinate(t_str room, char type)
{
	int		i;
	int		j;
	int		x_y;
	char	**coordinates;

	i = 0;
	j = 0;
	x_y = 0;
	coordinates = ft_strsplit(room, ' ');
	if (type == 'x')
		x_y = ft_atoi(coordinates[1]);
	else if (type == 'y')
		x_y = ft_atoi(coordinates[2]);
	return (x_y);
}

//Takes current maze, name + coordinates of room to add and 2D array
//with refs to all rooms it links to as well as
//type (i.e. start(0), end(2) or normal(1))
t_room	*new_maze(t_str room, unsigned int type, t_log *data, t_str *cur_links)
{
	t_room	**maze;
	t_room	*temp;
	int i;
	int j;
	int k;
	char **link_name;

	k = 0;
	maze = malloc(sizeof(t_room));
	(*maze)->room_type = type;
	(*maze)->name = ft_strdup(room);
	(*maze)->x = get_coordinate(room, 'x');
	(*maze)->y = get_coordinate(room, 'y');
	(*maze)->visited = 0;
	while (cur_links[k])
	{
		temp = malloc(sizeof(t_room));
		i = 0;
		j = 0;
		link_name = ft_strsplit(cur_links[j], '-');
		while (data->rooms[i])
		{
			if (ft_strequ(link_name[1], get_room_name(data->rooms[i])))
				break;
			i++;
		}
		if (i == data->start_index)
			temp->room_type = 0;
		else if (i == data->end_index)
			temp->room_type = 1;
		else
			temp->room_type = 2;
		temp->name = ft_strdup(*link_name);
		temp->x = get_coordinate(data->rooms[i], 'x');
		temp->y = get_coordinate(data->rooms[i], 'y');
		temp->visited = 0;
		temp->room_links = NULL;
		(*maze)->room_links[j++] = temp;
		k++;
		maze = &temp;
	}
	return (*maze);
}

t_room	*connect_links(t_log *data)
{
	t_room *maze;
	int i;
	char **cur_links;
	char *room_name;
	char *start_room;
	char *end_room;

	maze = NULL;
	i = 0;
	cur_links = (char**)malloc(sizeof(sizeof(char*)));
	start_room = data->rooms[data->start_index];
	end_room = data->rooms[data->end_index];
	while (data->rooms[i])
	{
		room_name = get_room_name(data->rooms[i]);
printf("%d: room_name = %s\n", i, room_name);
		cur_links = find_linked_rooms(room_name, data->links);
		if (i == data->start_index)
			maze = new_maze(data->rooms[i], 0, data, cur_links);
		else if (i == data->end_index)
			maze = new_maze(data->rooms[i], 1, data, cur_links);
		else
			maze = new_maze(data->rooms[i], 2, data, cur_links);
		i++;
	}
	return (maze);
}
