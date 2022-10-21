/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeghiaz <syeghiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:09:09 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 08:15:29 by syeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <stdint.h>

# include "dictionary.h"
# include "linkedlist.h"
# include "vector.h"
# include "cub3d_macros.h"
# include "cub3d_structs.h"
# include "cub3d_utils.h"

// validation
void		validate_texture_paths(t_data *input);
t_bool		validate_arguments(t_data *data);
t_bool		validate_map(t_data *data);
t_bool		validate_input_file(t_string input);

// parsing_utils.c
t_bool		is_start_of_map(t_string *str, int *return_value);
t_bool		is_attribute(t_string str);

// parsing.c
void		parse(t_string path, t_data *data);

// filling_map_data.c
int			get_sprites_count(t_list *list);
void		get_map_sprites(t_data *data);

// data.c
void		print_data(t_data *data);
t_data		*data_init(void);
t_bool		add_to_data(t_node *data_node, t_data *data);
void		mlx_data_init(t_data *data);

// game_manager.c
void		start_game(t_data	*data);
void		setup_player(t_data *data, int row, int col);

// game_manager_utils.c
t_bool		is_movement_key(int k_code);
t_bool		should_move(t_data *data);

// game_events.c
void		exit_game(t_data *data);
void		key_press(int key_code, t_data *data);
void		key_release(int key_code, t_data *data);

// player_movement.c
void		move_player(t_data *data);
void		rotate(t_data *data, int dir);

// fill_data.c
t_bool		fill_map_list(t_string line, t_data *data);
void		fill_map(t_string line, t_data *data);
t_bool		fill_attribute(t_string line, t_data *data);

// free_data.c
void		free_parsing_data(t_data *data);
void		full_free_data(t_data *data);

// mouse.c
t_mouse		init_mouse(void);
void		mouse_move(int x, int y, t_data *data);

// DRAWING

//draw_doors.c
void		draw_doors(t_data *data);

//draw_init_sides.c
void		init_wall_side_hit(t_data *data, t_draw *draw);
void		init_door_side_hit(t_data *data, t_draw *draw);
t_vector	init_side_dist(t_data *data, t_draw draw);

// draw_init_texture.c
double		init_tex_pos(t_draw draw);
int			init_tex_x(t_data *data, t_draw draw);

// draw_init.c
t_tuple		init_step(t_draw draw);
int			init_draw_end(t_draw draw);
int			init_draw_start(t_draw draw);
t_draw		init_draw(t_data *data, int col, char letter);

// draw_sprites.c
void		draw_sprites(t_data *data);

// drawing_utils.c
double		camera_x(int col);
double		perp_wall_dist(t_draw draw);
t_vector	init_delta_dist(t_draw draw);
t_vector	init_ray(t_data *data, int col);
double		wall_x(t_data *data, t_draw draw);

// drawer.c
void		draw(t_data *data);

// drawing_sprites_utils.c
int			tex_y(t_sprite_draw draw_data, int row);
int			tex_x(t_sprite_draw draw_data, int col);

//minimap.c
void		draw_minimap(t_data *data);

#endif
