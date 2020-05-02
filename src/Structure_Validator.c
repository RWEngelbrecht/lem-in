#include "../includes/colony.h"
#include <stdio.h>

int     validate_file(char *line) {
	int start = -1;
	int end = -1;
	int phase = 0; // Phase 0 = getting the number of ants.
	               // Phase 1 = Finding ##start and ##end AND setting up room array
	               // Phase 2 = the rooms getting linked
                   // Phase 3 = Completed successfully and return (1);
    while (get_next_line(0, &line))
        {
       		if (ft_only_digits(line) && phase == 0) {
//       			int ant_amnt = ft_atoi(line); should populate the struct
       			phase = 1;
       		} else if(is_comment(line)) {
                ft_putstr(line);
            }

            if (ft_strequ(line, "##start") && phase == 1) {
                start = 1;
            } else if (ft_strequ(line, "##end") && phase == 1) {
            	end = 1;
            } else if (is_room(line)) {
            	if (phase != 1)
            	    ORDER_ERR;
//            	data->rooms[++j] = ft_strdup(line);
            	if (start == 1) {
//            		data->start_index = j;
            		start = 0;
            	}
            	else if (end == 1) {
//            		data->end_index = j;
            		end = 0;
            	}
            } else if (is_link(line)) {
                if (phase == 1)
            		phase = 2;
            	if (phase == 0 || start < 0 || end < 0)
            		ORDER_ERR;
//            	data->links[++k] = ft_strdup(line);
            } else if (is_comment(line)) {
            	ft_putstr(line);
            }
            ft_putendl(line);
            free(line);
        }
        return (0);
}
