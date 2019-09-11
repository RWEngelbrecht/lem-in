/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:33:09 by jrheeder          #+#    #+#             */
/*   Updated: 2019/09/05 11:33:10 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colony.h"
#include <stdio.h>
int     check_name(t_log *data/*, int phase*/)
{
    // iterators
    int i;
    int j;
    int k;

    i = 0, k = 0;

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
    int k;
    char **roomName;

    i = 0;
    j = 0;
    k = 0;
    roomName = ft_strsplit(data->rooms[i], ' ');
    while (roomName[i])
    {
        
    }

}