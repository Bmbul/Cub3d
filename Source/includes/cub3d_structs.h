#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

typedef char				t_bool;
typedef char *				t_string;
typedef char **				t_text;
typedef struct s_textures	t_textures;
typedef struct s_texture	t_texture;
typedef struct s_data		t_data;
typedef struct s_color		t_color;
typedef struct s_player		t_player;
typedef struct s_img		t_img;

struct s_player
{
	t_vector	pos;
	t_vector	dir;
};

struct s_img
{
	int			endian;
	void		*img_ptr;
	int			size_line;
	char		*data_addr;
	int			bits_per_pixel;
};

struct s_data
{
	void		*mlx;
	void		*window;
	t_img		frame;
	int			fd;
	t_text		map;
	int			map_width;
	int			map_height;
	t_color		*floor_color;
	t_color		*ceiling_color;
	t_string	texture_paths[4];
	t_text		color_strings;
	t_dict		*input_dict;
	t_textures	*textures;
	t_list		*map_list;
	t_player	player;
	t_vector	camera_plane;
};

struct s_mlx
{
	void		*mlx;
	void		*window;
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
	t_texture	*north;
	t_texture	*east;
	t_texture	*west;
	t_texture	*south;
};

struct s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
};

#endif
