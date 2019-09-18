/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:34:57 by rengelbr          #+#    #+#             */
/*   Updated: 2019/09/17 14:47:05 by rengelbr         ###   ########.fr       */
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
// t_room	*new_maze(t_str room, unsigned int type, t_log *data, t_str *cur_links)
// {
// 	t_room	*maze;
// 	t_room	**temp1;
// 	t_room	*temp2;
// 	int		i;
// 	int		j;
// 	int		k;
// 	char	**link_name;

// 	k = 0;
// 	j = 0; //mm
// printf("starting 1\n");
// 	maze = malloc(sizeof(t_room));
// 	temp1 = &maze;
// printf("room : %s\n type : %d\n cur_links : %s\ncur_links : %s\n", room, type, cur_links[0], cur_links[1]);
// 	(*temp1)->room_type = (unsigned int)malloc(sizeof(unsigned int)*200);
// 	(*temp1)->room_type = type;
// printf("does it do this though?\n");
// 	(*temp1)->name = get_room_name(room);
// printf("temp1->name = %s\n", (*temp1)->name);
// 	(*temp1)->x = get_coordinate(room, 'x');
// 	(*temp1)->y = get_coordinate(room, 'y');
// 	(*temp1)->visited = 0;
// printf("temp1->x = %d\ntemp1->y = %d\n", (*temp1)->x, (*temp1)->y);
// 	(*temp1)->next = NULL;
// 	while (cur_links[k])
// 	{
// printf("starting 2\n");
// 		temp2 = (t_room*)malloc(sizeof(t_room));
// 		i = 0;
// 		link_name = ft_strsplit(cur_links[j], '-');
// printf("link_name: %s\n", link_name[0]);
// printf("link_name: %s\n", link_name[1]);
// 		while (data->rooms[i])
// 		{
// 			if (ft_strequ(link_name[1], get_room_name(data->rooms[i])))
// 			{
// printf("GRN: %s\n", get_room_name(data->rooms[i]));
// 				break;
// 			}
// 			i++;
// 		}
// 		if (i == data->start_index)
// 			temp2->room_type = 0;
// 		else if (i == data->end_index)
// 			temp2->room_type = 1;
// 		else
// 			temp2->room_type = 2;
// 		temp2->name = ft_strdup(link_name[1]);
// 		temp2->x = get_coordinate(data->rooms[i], 'x');
// 		temp2->y = get_coordinate(data->rooms[i], 'y');
// 		temp2->visited = 0;
// 		temp2->room_links[k] = NULL;
// printf("t->name: %s\nt->x: %d, t->y: %d\n", temp2->name, temp2->x, temp2->y);
// 		(*temp1)->room_links[j] = temp2;
// printf("that worked\n");
// 		j++;
// 		k++;
// 	}
// 	return (*temp1);
// }

t_room	*new_maze(t_str room, unsigned int type)
{
	t_room	*maze;

	maze = malloc(sizeof(t_room));
	maze->room_type = type;
	maze->name = get_room_name(room);
	maze->x = get_coordinate(room, 'x');
	maze->y = get_coordinate(room, 'y');
	maze->visited = 0;
	maze->next = NULL;
	return (maze);
}

void	add_room(t_room **maze, t_str room, unsigned int type)
{
	t_room *new_room;

	new_room = malloc(sizeof(t_room));
	new_room->room_type = type;
	new_room->name = get_room_name(room);
	new_room->x = get_coordinate(room, 'x');
	new_room->y = get_coordinate(room, 'y');
	new_room->visited = 0;
	new_room->next = *maze;
	*maze = new_room;
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
	room_name = get_room_name(data->rooms[i]);
	cur_links = find_linked_rooms(room_name, data->links);
	while (data->rooms[i])
	{
		if (!maze)
		{
			if (i == data->start_index)
				maze = new_maze(data->rooms[i], 0);
			else if (i == data->end_index)
				maze = new_maze(data->rooms[i], 1);
			else
				maze = new_maze(data->rooms[i], 2);
		}
		else
		{
			if (i == data->start_index)
				add_room(&maze, data->rooms[i], 0);
			else if (i == data->end_index)
				add_room(&maze, data->rooms[i], 1);
			else
				add_room(&maze, data->rooms[i], 2);
		}
		i++;
	}
	return (maze);
}
	1 -- 2 --- 6
  /    			\
0 --- 3 -|		 ---end
  \				/
   4 ---- 5 ---


Node 0 contains 1, 3, 4 sub-nodes
1 contains 2 
3 contains nothing
4 contains 5
6 contains end
5 contains end

Not sure how you want to implement it? But was thinking of creating another linked list and have sub-nodes which then 
contains 2 which then can contain 6 and so on.