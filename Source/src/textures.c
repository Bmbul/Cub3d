#include "../includes/cub3d.h"

t_img	img_init(t_data *data, char *addr)
{
	t_img	img;

	img.data_addr = NULL;
	img.img_ptr = mlx_xpm_file_to_image(data->mlx, addr,
			&img.size.x, &img.size.y);
	img.data_addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.size_line, &img.endian);
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

unsigned int	get_img_color(t_img img, int x, int y)
{
	char	*dst;

	dst = img.data_addr + (y * img.size_line + x * (img.bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}
