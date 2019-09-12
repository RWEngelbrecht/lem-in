/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:33:09 by jrheeder          #+#    #+#             */
/*   Updated: 2019/09/12 10:01:56 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colony.h"
#include "../libft/libft.h"
#include <stdio.h>
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
			{
				ft_putstr_fd("Error\n", 2);
				exit(2);
			}
			j++;
		}
		i++;
    }
    i = 0;
    return (1);
}
