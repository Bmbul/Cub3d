/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:09:06 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:17:11 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

typedef char					t_bool;
typedef char *					t_string;
typedef char **					t_text;
typedef struct s_textures		t_textures;
typedef struct s_texture		t_texture;
typedef struct s_color			t_color;
typedef struct s_player			t_player;
typedef struct s_img			t_img;
typedef struct s_key_map		t_key_map;
typedef struct s_data			t_data;
typedef struct s_mov_inp		t_mov_inp;
typedef struct s_draw			t_draw;
typedef struct s_sprite_draw	t_sprite_draw;
typedef struct s_sprite_info	t_sprite_info;
typedef struct s_mouse			t_mouse;
typedef struct s_anim_sprite	t_animated_sprite;
typedef struct s_minimap		t_minimap;

struct s_minimap {
	int				ver_block;
	int				hor_block;
	int				ver_pixel;
	int				hor_pixel;
	int				ver_scale;
	int				hor_scale;
	unsigned int	color;
};

struct s_mouse {
	int	hor;
	int	ver;
};

struct s_draw {
	int			hit;
	t_vector	ray;
	t_tuple		map;
	t_vector	delta_dist;
	t_vector	side_dist;
	t_tuple		step;
	int			side;
	int			line_height;
	int			ceiling_size;
	int			tex_x;
	int			draw_start;
	int			draw_end;
	double		ratio;
	double		tex_pos;
};

struct s_sprite_draw
{
	t_vector	pos;
	double		inv_det;
	int			sprite_screenx;
	int			sprite_height;
	t_vector	transform;
	int			texture_width;
	int			texture_height;
	int			draw_starty;
	int			draw_endy;
	int			sprite_width;
	int			draw_startx;
	int			draw_endx;
	int			i;
};

struct s_player
{
	t_vector	pos;
	t_vector	dir;
};

struct s_img
{
	t_tuple			size;
	int				endian;
	void			*img_ptr;
	int				size_line;
	char			*data_addr;
	int				bits_per_pixel;
	unsigned int	*texture;
};

struct s_texture
{
	void	*mlx_img;
	char	*addr;
	int		width;
	int		height;
};

struct s_textures
{
	t_img	north;
	t_img	east;
	t_img	west;
	t_img	south;
};

struct s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
};

struct s_key_map
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
};

struct s_mov_inp
{
	int	x;
	int	y;
	int	rot;
};

struct s_anim_sprite
{
	unsigned int	current_index;
	unsigned int	current_frame;
	unsigned int	frames_count;
	unsigned int	sprites_count;
	t_img			*sprites;
};

struct s_sprite_info
{
	t_vector	pos;
	int			texture;
};

struct s_data
{
	void				*mlx;
	void				*window;
	t_img				frame;
	int					fd;
	t_text				map;
	int					map_width;
	int					map_height;
	int					sprites_count;
	t_color				*floor_color;
	t_color				*ceiling_color;
	t_string			texture_paths[4];
	t_text				color_strings;
	t_dict				*input_dict;
	t_textures			*textures;
	t_list				*map_list;
	t_player			player;
	t_mouse				mouse;
	t_vector			camera_plane;
	t_key_map			key_map;
	t_mov_inp			mov_input;
	t_animated_sprite	*a_sprites;
	t_sprite_info		*map_sprites;
	int					*sprite_order;
	double				*sprite_distance;
	double				z_buffer[WIN_WIDTH];
};

#endif
