#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

# include "linkedlist.h"
# include "cub3d_structs.h"
# include "cub3d_macros.h"
# include "cub3d_utils.h"
// validation
t_bool	validate_input_file(t_string input);
t_bool	validate_input_paths(t_data *data);
t_bool	validate_map(t_data *data);

// parsing_utils.c
t_bool	is_start_of_map(t_string str, int *return_value);
t_bool	is_attribute(t_string str);

// parsing
t_bool	parse(t_string path, t_data *data);


// data.c
void	print_data(t_data *data);
t_data	*init_data(void);
t_bool	add_to_data(t_node *data_node, t_data *data);

// free_data.c
void	free_data(t_data *data);

// game_manager.c
void	start_game(t_data *data);

#endif