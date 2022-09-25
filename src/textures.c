#include "cub3d.h"

t_img	img_init(t_data *data, char *addr)
{
	t_img	img;

	img.addr = addr;
	img.mlx_img = mlx_xpm_file_to_image(data->mlx, img.addr,
			&img.width, &img.height);
	return (img);
}

void	textures_init(t_data *data)
{
	data->textures = malloc(sizeof(t_textures));
	data->textures->north = img_init(data, data->texture_paths[_NORTH]);
	data->textures->east = img_init(data, data->texture_paths[_EAST]);
	data->textures->west = img_init(data, data->texture_paths[_WEST]);
	data->textures->south = img_init(data, data->texture_paths[_SOUTH]);
}