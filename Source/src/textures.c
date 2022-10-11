#include "../includes/cub3d.h"

t_img	img_init(t_data *data, char *addr)
{
	t_img	img;

	img.data_addr = NULL;
	img.img_ptr = mlx_xpm_file_to_image(data->mlx, addr,
			&img.size.x, &img.size.y);
	img.data_addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.size_line, &img.endian);
	img.texture = get_img_colors(img);
	return (img);
}

void	sprites_init(t_data *data)
{
	data->sprites = malloc(sizeof(t_img *) * SPRITES_COUNT);
	data->sprites[ENEMY_INDEX] = malloc(sizeof(t_img) * 3);
	data->sprites[ENEMY_INDEX][0] = img_init(data, "textures/enemy0.xpm");
	data->sprites[ENEMY_INDEX][1] = img_init(data, "textures/enemy1.xpm");
	data->sprites[ENEMY_INDEX][2] = img_init(data, "textures/enemy2.xpm");
}

void	textures_init(t_data *data)
{
	data->textures = malloc(sizeof(t_textures));
	data->textures->north = img_init(data, data->texture_paths[_NORTH]);
	data->textures->east = img_init(data, data->texture_paths[_EAST]);
	data->textures->west = img_init(data, data->texture_paths[_WEST]);
	data->textures->south = img_init(data, data->texture_paths[_SOUTH]);
	sprites_init(data);
}
