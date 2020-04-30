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

	// int i = 0;
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
	// TODO: Perform algorithm
	// TODO: Print everything
}
