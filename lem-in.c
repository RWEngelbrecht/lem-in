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
	t_str *raw_data;
	// t_log *ret;
//	t_room *maze;

	line = NULL;
//printf("reading input\n");
	raw_data = read_input(line);				//*****DOES NOT LEAK****
//printf("input read\n");
   if (validate_file(raw_data)) {
        printf("validated");
   }
//printf("validating input\n");
//	validate(ret);						//******LEAKS A F##K TON****
//printf("input validated\n");
//printf("mapping input\n");
//	maze = init_rooms(ret);				//*****SOMEWHAT LEAKY******
//printf("input initialized\n");
	// TODO: Perform algorithm
	// TODO: Print everything
}
