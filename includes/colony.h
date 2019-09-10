/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colony.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:35:08 by jrheeder          #+#    #+#             */
/*   Updated: 2019/09/10 15:38:48 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/libft.h"

typedef struct		s_room
{
	int				start;
	int				end;
	char			*name;
	int				x;
	int				y;
	int				ants;
	struct s_room	*next;
}					t_room;

typedef struct		s_log
{
	int				ant_amnt;
	int				start_line;
	int				end_line;
	char			**rooms;
	char			**links;
}					t_log;


char	*get_room_name(char *line);
t_log	*read_input(char **line);

#endif
