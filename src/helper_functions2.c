/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:34:57 by rengelbr          #+#    #+#             */
/*   Updated: 2020/05/21 16:24:43 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colony.h"

void free_path(t_path *the_path)
{
	t_path *temp;

	while (the_path != NULL)
	{
		temp = the_path;
		the_path = the_path->next;
		free(temp->room_name);
		free(temp);
	}
}

void ft_putroom(int ant_name, char *room_name)
{
	ft_putstr("L");
	ft_putnbr(ant_name);
	ft_putstr("-");
	ft_putstr(room_name);
	ft_putstr(" ");
}