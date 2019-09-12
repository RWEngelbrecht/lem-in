/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colony.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:35:08 by jrheeder          #+#    #+#             */
/*   Updated: 2019/09/12 12:25:44 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define ERROR {ft_putstr_fd("Error\n", 2); exit(2);}
#include "../libft/libft.h"

typedef struct		s_room
{
	unsigned int	room_type : 2;
	char			*name;
	unsigned int	x : 8;
	unsigned int	y : 8;
	unsigned int	visited;
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


char	*get_room_name(char *room);
t_log	*read_input(char **line);
int		check_name(t_log *data/*, int phase*/);
int		check_name_XY(t_log *data);
int		check_links(t_log *data);
void	validate(t_log *data);

#endif
