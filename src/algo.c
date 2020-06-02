/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:28:51 by hde-vos           #+#    #+#             */
/*   Updated: 2020/05/29 15:10:25 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colony.h"

int room_in_path(t_path *the_path, t_str room_name)
{
	t_path *temp;

	temp = the_path;
	while (temp->next)
	{
		if (ft_strequ(temp->room_name, room_name)) {
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

int pathequ(t_path *path1, t_path *path2)
{
	t_path *temp1;
	t_path *temp2;

	temp1 = path1;
	temp2 = path2;
	while (temp1 && temp2)
	{
		if (!ft_strequ(temp1->room_name, temp2->room_name))
			return (0);
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return (1);
}

int path_exists(t_path **paths, t_path *path, int path_count)
{
	int i;

	i = -1;
	if (path_count == 0)
		return (0);
	while (++i < path_count)
	{
		if (pathequ(paths[i], path))
			return (1);
	}
	return (0);
}

t_room *find_least_visited(t_links *room_links)
{
	t_links *next_link;
	t_links *ret_link;

	ret_link = room_links;
	if (ret_link)
	{
		next_link = ret_link->next;
		while (next_link)
		{
			if ((ret_link->room->dead_end || ret_link->room->room_type == 0))
				ret_link = next_link;
			else if (ret_link->room->visited > next_link->room->visited && !next_link->room->dead_end)
				ret_link = next_link;
			next_link = next_link->next;
		}
		return (ret_link->room);
	}
	return (NULL);
}

t_path	*algo(t_log *node_array)
{
	t_room	*current_room;
	t_room	*previous_room;
	t_path	*the_path;
	t_path	**paths;
	int			found;
	int 		i;

	current_room = node_array->rooms[node_array->start_index];
	the_path = NULL;
	paths = (t_path **)malloc(sizeof(t_path*) * (node_array->room_count + 1));
	found = 0;
	while (node_array->rooms[node_array->start_index]->visited < node_array->room_count)
	{
		previous_room = current_room;
		current_room = find_least_visited(current_room->room_links);
		if (!the_path)
		{
			the_path = start_path(current_room->name);
			if (current_room->room_type == 1)
			{
				paths[found] = copy_path(the_path);
				found++;
				break;
			}
		}
		else if (!room_in_path(the_path, current_room->name) && current_room->room_type != 0)
		{
			add_to_path(the_path, current_room->name);
			if (current_room->room_type == 1 && !path_exists(paths, the_path, found))
			{
				paths[found] = copy_path(the_path);
				free_path(the_path);
				the_path = NULL;
				current_room = node_array->rooms[node_array->start_index];
				found++;
			}
		}
		else
		{
			previous_room->dead_end = 1;
			free_path(the_path);
			the_path = NULL;
			current_room = node_array->rooms[node_array->start_index];
		}
		current_room->visited++;
	}
	if (found < 1)
	{
		SOLVE_ERR;
		free(paths);
		return (NULL);
	}
	else
	{
		free_path(the_path);
		the_path = copy_path(shortest_path(paths, found));
		i = 0;
		while (paths[i])
			free_path(paths[i++]);
		free(paths);
	}
	return (the_path);
}
