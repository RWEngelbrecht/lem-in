/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:28:51 by jrheeder          #+#    #+#             */
/*   Updated: 2020/05/22 16:43:29 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/colony.h"

void ft_putroom(int ant_name, char *room_name)
{
	ft_putstr("L");
	ft_putnbr(ant_name);
	ft_putstr("-");
	ft_putstr(room_name);
	ft_putstr(" ");
}

void free_ant(t_ants *ants, t_ants *ant)
{
	t_ants *curr_ant;
	t_ants *next_ant;
	t_ants *prev_ant;

	curr_ant = ants;
	while (ants->ant_name != ant->ant_name)
		curr_ant = curr_ant->next;
	if (curr_ant->prev)
		prev_ant = curr_ant->prev;
	if (curr_ant->next)
		next_ant = curr_ant->next;
	free(curr_ant);
	prev_ant->next = next_ant;
	next_ant->prev = prev_ant;
}

void generate_moves(t_ants *ants, t_path *the_path, t_log *node_array)
{
	t_ants	*last_ant;
	t_ants	*curr_ant;
	t_ants	*temp_ants;
	int			i;

	i = 1;
	last_ant = ants->next;
	while (i == 1)
	{
		i = 0;
		curr_ant = ants;
		while (curr_ant != last_ant)
		{
			 i = 1;
			if (!curr_ant->room)
				curr_ant->room = the_path;
			else if (!ft_strequ(curr_ant->room->room_name, node_array->rooms[node_array->end_index]->name))
				curr_ant->room = curr_ant->room->next;
			ft_putroom(curr_ant->ant_name, curr_ant->room->room_name);
			if (ft_strequ(curr_ant->room->room_name, node_array->rooms[node_array->end_index]->name))
			{
				temp_ants = ants->next;
				free(ants);
				ants = temp_ants;
			}
			if (curr_ant->next)
				curr_ant = curr_ant->next;
		}
		if (i == 1)
			ft_putstr("\n");
		if (curr_ant->next)
			last_ant = curr_ant->next;
	}
}

t_ants *create_ants(int ant_amount)
{
	int i;
	t_ants *prev_ant;
	t_ants *curr_ant;
	t_ants *head;

	i = 1;
	prev_ant = NULL;
	while (i <= ant_amount)
	{
		curr_ant = (t_ants *)malloc(sizeof(t_ants));
		curr_ant->ant_name = i;
		curr_ant->room = NULL;
		if (prev_ant)
		{
			prev_ant->next = curr_ant;
			curr_ant->prev = prev_ant;
		}
		else
		{
			head = curr_ant;
			curr_ant->prev = NULL;
		}
		prev_ant = curr_ant;
		i++;
	}
	curr_ant->next = NULL;
	return (head);
}

int main()
{
	char *line;
	t_str *raw_data;
	t_log *node_array;
	t_path *the_path;
	t_path *the_temp;
	t_ants *ants;
	t_ants *temp;

	line = NULL;
	raw_data = read_input(line);
	validate_file(raw_data);
	node_array = create_node_array(raw_data);
	the_path = algo(node_array);

	the_temp = the_path;
	while (the_temp)
	{
		ft_putstr(the_temp->room_name);
		ft_putstr("\n");
		the_temp = the_temp->next;
	}

	ants = create_ants(node_array->ant_amnt + 1);
	generate_moves(ants, the_path, node_array);
	return (0);
}

// temp = ants;
// while (temp)
// {
// 	ft_putnbr(temp->ant_name);
// 	ft_putstr(" ");
// 	temp = temp->next;
// 	ft_putstr("\n");
// }
// temp = ants;
// while (temp)
// {
// 	if (!temp->next)
// 		break ;
// 	temp = temp->next;
// }
// while (temp)
// {
// 	ft_putnbr(temp->ant_name);
// 	ft_putstr(" ");
// 	temp = temp->prev;
// 	ft_putstr("\n");
// }

// curr_ant = ants;
// if (!curr_ant->room)
// 	curr_ant->room = the_path;
// if (curr_ant->room)
// 	while (curr_ant->room == node_array->rooms[node_array->end_index])
// 		curr_ant->room = curr_ant->room->next;
// while (curr_ant->room)
// {
// 	if (!curr_ant->room)
// 		curr_ant->room = the_path;
// 	if (curr_ant->room)
// 		curr_ant->room = curr_ant->room->next;
// 	ft_putstr("L");
// 	ft_putnbr(curr_ant->ant_name);
// 	ft_putstr("-");
// 	ft_putstr(curr_ant->room->room_name);
// 	curr_ant = curr_ant->next;
// 	ft_putstr(" ");
// }
// ft_putstr("\n");
// last_ant = last_ant->next;
