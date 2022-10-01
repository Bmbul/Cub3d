#ifndef CUB3D_H
# define CUB3D_H


# ifdef __linux__
#  include "../../mlx_linux/mlx.h"
# else
#  include "../../mlx_macos/mlx.h"
# endif

# include <math.h>
# include <unistd.h>
# include <fcntl.h>
//# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
//# include <mlx.h>

# include "dictionary.h"
# include "linkedlist.h"
# include "vector.h"
# include "cub3d_macros.h"
# include "cub3d_structs.h"
# include "cub3d_utils.h"

// validation
t_bool		validate_texture_paths(t_data *input);
t_bool		validate_arguments(t_data *data);
t_bool		validate_map(t_data *data);
t_bool		validate_input_file(t_string input);

// parsing_utils.c
t_bool		is_start_of_map(t_string str, int *return_value);
t_bool		is_attribute(t_string str);

// parsing
t_bool		parse(t_string path, t_data *data);

// data.c
void		print_data(t_data *data);
t_data		*data_init(void);
t_bool		add_to_data(t_node *data_node, t_data *data);
void		mlx_data_init(t_data *data);

// drawer.c
void		draw_map(t_data *data);

// game_manager.c
void		move_player(int k_code, t_data *data);
void		setup_player(t_data *data, int row, int col);

// fill_data.c
t_bool		fill_map_list(t_string line, t_data *data);
void		fill_map(t_string line, t_data *data);
t_bool		fill_attribute(t_string line, t_data *data);

// free_data.c
void		free_data(t_data *data);

// game_manager.c
void		start_game(t_data *data);

// textures.c
t_texture		*img_init(t_data *data, char *addr);
void		textures_init(t_data *data);

// drawer.c
void		draw(t_data *data);
void		verLine(t_data *data, int i, int drawStart, int drawEnd, t_color color);
#endif
