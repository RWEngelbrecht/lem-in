#include "../includes/colony.h"
#include <stdio.h>

int    validate_file(t_str *data) {
	int start;
	int end;
	int phase;
	int i;
	int j;
	int k;

//	data = (t_log*)malloc(sizeof(t_log));
//	data->rooms = (char**)malloc(sizeof(char*) * 2048);
//	data->links = (char**)malloc(sizeof(char*) * 2048);
	start = -1;
	end = -1;
	phase = 0;
	i = 0;
	j = -1;
	k = -1;        // Phase 0 = getting the number of ants.
	               // Phase 1 = Finding ##start and ##end AND setting up room array
	               // Phase 2 = the rooms getting linked
                   // Phase 3 = Completed successfully and return (1);
    while (data[i])
        {
       		if (ft_only_digits(data[i]) && phase == 0) {
//       			data->ant_amnt = ft_atoi(line);
       			phase = 1;
       		}
//       		else if(is_comment(data[i])) {
//                ft_putstr(data[i]);
//            }

            if (ft_strequ(data[i], "##start") && phase == 1) {
                start = 1;
            } else if (ft_strequ(data[i], "##end") && phase == 1) {
            	end = 1;
            } else if (is_room(data[i])) {
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
            } else if (is_link(data[i])) {
                if (phase == 1)
            		phase = 2;
            	if (phase == 0 || start < 0 || end < 0)
            		ORDER_ERR;
//            	data->links[++k] = ft_strdup(line);
            }
//            else if (is_comment(data[i])) {
//            	ft_putstr(data[i]);
//            }
            ft_putendl(data[i]);
            i++;
        }
        return (1); // Structure is correct (We want to be returning some data instead)
}
