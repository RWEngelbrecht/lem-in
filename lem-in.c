/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:28:51 by jrheeder          #+#    #+#             */
/*   Updated: 2019/09/22 18:06:13 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/colony.h"
#include <stdio.h>
int main()
{
	char *line;
	t_log *ret;
	t_room *maze;
//	int i = 0;
//	 int j = 0;
//	int valid;

	line = NULL;
printf("reading input\n");
	ret = read_input(line);				//*****DOES NOT LEAK****
printf("input read\n");
printf("validating input\n");
	validate(ret);						//******LEAKS A F##K TON****
printf("input validated\n");
printf("mapping input\n");
	maze = init_rooms(ret);				//*****SOMEWHAT LEAKY******
printf("input initialized\n");
//while (maze)
//{
	// while (maze->room_links[i])
	// {
//		printf("room(%d): type = %d\nname = %s\nXY = %d %d\nvisited = %d\n",i, maze->room_type, maze->name, maze->x, maze->y, maze->visited);
//		i++;
	// }
//	maze = maze->next;
//}
// while (ret->rooms[i])
// {
// 	printf("rooms[%d] = %s\n", i, ret->rooms[i]);
// 	i++;
// }
// while (ret->links[j])
// {
// 	printf("links[%d] = %s\n", j, ret->links[j]);
// 	j++;
// }
	//valid = check_name_XY(ret);
//printf("VALID CHECK: %d\n", check_links(ret));
//	printf("ant amnt = %d\nstart_line = %d\nend_line = %d\n", ret->ant_amnt, ret->start_line, ret->end_line);

}
