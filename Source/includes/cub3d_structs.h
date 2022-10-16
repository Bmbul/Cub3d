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
typedef struct s_sprite_info	t_sprite_info;
typedef struct s_mouse			t_mouse;

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
	int			lineHeight;
	int			ceiling_size;
	int			texX;
	int			drawStart;
	int			drawEnd;
	double		ratio;
	double		texPos;
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

struct s_sprite_info
{
	t_tuple	pos;
	int		texture;
};

struct s_data
{
	void			*mlx;
	void			*window;
	t_img			frame;
	int				fd;
	t_text			map;
	int				map_width;
	int				map_height;
	int				sprites_count;
	t_color			*floor_color;
	t_color			*ceiling_color;
	t_string		texture_paths[4];
	t_text			color_strings;
	t_dict			*input_dict;
	t_textures		*textures;
	t_list			*map_list;
	t_player		player;
	t_mouse			mouse;
	t_vector		camera_plane;
	t_key_map		key_map;
	t_mov_inp		mov_input;
	t_img			**sprites;
	t_list			*drawing_sprites;
	t_sprite_info	*map_sprites;
	int				*sprite_order;
	double			*sprite_distance;
	double			z_buffer[WIN_WIDTH];
};

#endif
