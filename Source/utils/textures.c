/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeghiaz <syeghiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:10:23 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/22 22:39:36 by syeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_img	img_init(void *mlx, char *addr)
{
	t_img	img;

	img.data_addr = NULL;
	img.img_ptr = mlx_xpm_file_to_image(mlx, addr,
			&img.size.x, &img.size.y);
	img.data_addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.size_line, &img.endian);
	img.texture = get_img_colors(img);
	return (img);
}

static void	enemy_sprites_init(t_data *data)
{
	data->a_sprites[ENEMY_INDEX].sprites = malloc(sizeof(t_img) * 3);
	data->a_sprites[ENEMY_INDEX].current_index = 0;
	data->a_sprites[ENEMY_INDEX].current_frame = 0;
	data->a_sprites[ENEMY_INDEX].sprites_count = 3;
	data->a_sprites[ENEMY_INDEX].frames_count = ANIM_CHANGE_FRAME;
	data->a_sprites[ENEMY_INDEX].sprites[0]
		= img_init(data->mlx, "textures/enemy0.xpm");
	data->a_sprites[ENEMY_INDEX].sprites[1]
		= img_init(data->mlx, "textures/enemy1.xpm");
	data->a_sprites[ENEMY_INDEX].sprites[2]
		= img_init(data->mlx, "textures/enemy2.xpm");
}

static void	sprites_init(t_data *data)
{
	data->a_sprites = malloc(sizeof(t_animated_sprite) * SPRITES_COUNT);
	enemy_sprites_init(data);
}

void	door_init(t_data *data)
{
	data->door_frames = malloc(sizeof(t_door_sprites));
	data->door_frames[0].sprites = malloc(sizeof(t_img) * 7);
	data->door_frames[0].sprites[0]
		= img_init(data->mlx, "textures/door0.xpm");
	data->door_frames[0].sprites[1]
		= img_init(data->mlx, "textures/door1.xpm");
	data->door_frames[0].sprites[2]
		= img_init(data->mlx, "textures/door2.xpm");
	data->door_frames[0].sprites[3]
		= img_init(data->mlx, "textures/door3.xpm");
	data->door_frames[0].sprites[4]
		= img_init(data->mlx, "textures/door4.xpm");
	data->door_frames[0].sprites[5]
		= img_init(data->mlx, "textures/door5.xpm");
	data->door_frames[0].sprites[6]
		= img_init(data->mlx, "textures/door6.xpm");
}

void	textures_init(t_data *data)
{
	data->textures = malloc(sizeof(t_textures));
	data->textures->north = img_init(data->mlx, data->texture_paths[_NORTH]);
	data->textures->east = img_init(data->mlx, data->texture_paths[_EAST]);
	data->textures->west = img_init(data->mlx, data->texture_paths[_WEST]);
	data->textures->south = img_init(data->mlx, data->texture_paths[_SOUTH]);
	data->textures->door = img_init(data->mlx, "textures/door1.xpm");
	sprites_init(data);
	door_init(data);
}
