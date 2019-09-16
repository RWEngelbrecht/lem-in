/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colony.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:35:08 by jrheeder          #+#    #+#             */
/*   Updated: 2019/09/16 12:29:44 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define NAME_ERROR {ft_putstr_fd("Error: Room names incorrect\n", 2); exit(2);}
# define LINKS_ERROR {ft_putstr_fd("Error: Room links incorrect\n", 2); exit(2);}
# define XY_ERROR {ft_putstr_fd("Error: Room coordinates incorrect\n", 2); exit(2);}
# define ORDER_ERROR {ft_putstr_fd("Error: Incorrect order in input\n", 2); exit(2);}
#include "../libft/libft.h"

typedef char *t_str;

typedef struct		s_room
{
	unsigned int	room_type : 2;
	t_str			name;
	unsigned int	x : 8;
	unsigned int	y : 8;
	unsigned int	visited;
	struct s_room	**room_links;
}					t_room;

typedef struct		s_log
{
	int				ant_amnt;
	int				start_index;
	int				end_index;
	t_str			*rooms;
	t_str			*links;
}					t_log;


char	*get_room_name(char *room);
t_log	*read_input(char *line);
int		check_name(t_log *data/*, int phase*/);
int		check_name_XY(t_log *data);
int		check_links(t_log *data);
void	validate(t_log *data);
void	map_links(t_log *data);

#endif
