#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

# include "cub3d_structs.h"
# include "cub3d_macros.h"
# include "cub3d_utils.h"
# include "linkedlist.h"
// validation
t_bool	validate_input_file(t_string input);
t_bool	validate_input_paths(t_data *data);
t_bool	validate_map(t_data *data);

// parsing
t_bool	parse(t_string path, t_data *data);


// init_data.c
t_data	*init_data(void);

// free_data.c
void	free_data(t_data *data);

// game_manager.c
void	start_game(t_data *data);

#endif