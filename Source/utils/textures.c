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
	data->a_sprites = malloc(sizeof(t_animated_sprite) * SPRITES_COUNT);
	data->a_sprites[ENEMY_INDEX].sprites = malloc(sizeof(t_img) * 3);
	data->a_sprites[ENEMY_INDEX].current_index = 0;
	data->a_sprites[ENEMY_INDEX].current_frame = 0;
	data->a_sprites[ENEMY_INDEX].sprites_count = 3;
	data->a_sprites[ENEMY_INDEX].frames_count = ANIM_CHANGE_FRAME;
	data->a_sprites[ENEMY_INDEX].sprites[0]
		= img_init(data, "textures/enemy0.xpm");
	data->a_sprites[ENEMY_INDEX].sprites[1]
		= img_init(data, "textures/enemy1.xpm");
	data->a_sprites[ENEMY_INDEX].sprites[2]
		= img_init(data, "textures/enemy2.xpm");
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

t_sprite_info	new_sprite_info(int x, int y, int texture)
{
	t_sprite_info	sprite;

	sprite.pos = new_tuple(x, y);
	sprite.texture = texture;
	return (sprite);
}

unsigned int	get_animated_sprite_color(char letter,
	t_data *data, int x, int y)
{
	unsigned int		color;
	t_animated_sprite	current_sprite;

	if (letter == ENEMY)
	{
		current_sprite = data->a_sprites[ENEMY_INDEX];
		color = get_img_color(current_sprite.sprites
			[current_sprite.current_index], x, y);
	}
	else
		color = 0;
	return (color);
}
