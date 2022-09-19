#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

typedef char				t_bool;
typedef char *				t_string;
typedef char **				t_text;
typedef struct s_textures	t_textures;

typedef struct data
{
	void		*mlx;
	void		*mlx_window;

	t_text		*map;
	t_textures	*textures;	
}				t_data;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		width;
	int		height;
}				t_img;


typedef struct s_textures
{
	t_img	north;
	t_img	east;
	t_img	west;
	t_img	south;
	t_img	floor;
	t_img	ceiling;
}				t_textures;
#endif