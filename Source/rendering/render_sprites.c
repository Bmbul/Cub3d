/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeghiaz <syeghiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:09:37 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 07:51:56 by syeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sort_sprites(t_data *data)
{
	int		i;
	t_order	*sprites;

	i = -1;
	while (++i < data->sprites_count)
	{
		data->sprite_order[i] = i;
		data->sprite_distance[i] = ((data->player.pos.x
					- data->map_sprites[i].pos.x)
				* (data->player.pos.x - data->map_sprites[i].pos.x)
				+ (data->player.pos.y - data->map_sprites[i].pos.y)
				* (data->player.pos.y - data->map_sprites[i].pos.y));
	}
	sprites = malloc(sizeof(t_order) * data->sprites_count);
	i = -1;
	while (++i < data->sprites_count)
		sprites[i] = new_order(data->sprite_order[i], data->sprite_distance[i]);
	sort_order(sprites, data->sprites_count);
	i = -1;
	while (++i < data->sprites_count)
	{
		data->sprite_order[i] = sprites[data->sprites_count - i - 1].order;
		data->sprite_distance[i] = sprites[data->sprites_count - i - 1].dist;
	}
	free(sprites);
}

static void	draw_sprite(t_data *data, t_sprite_draw draw_data)
{
	int				row;
	int				col;
	unsigned int	color;

	col = draw_data.draw_startx - 1;
	while (++col < draw_data.draw_endx)
	{
		if (draw_data.transform.y > 0 && draw_data.transform.y
			< data->z_buffer[col])
		{
			row = draw_data.draw_starty - 1;
			while (++row < draw_data.draw_endy)
			{
				color = get_animated_sprite_color(data->map_sprites[draw_data.i]
						.texture, data, tex_x(draw_data, col),
						tex_y(draw_data, row));
				if ((color & 0x00FFFFFF) != 0)
					*(unsigned int *)(data->frame.data_addr
							+ (row * data->frame.size_line + col
								* (data->frame.bits_per_pixel / 8)))
						= color;
			}
		}
	}
}

static void	setup_data(t_sprite_draw	*draw_data)
{
	draw_data->sprite_screenx = (int)((WIN_WIDTH / 2)
			* (1 + draw_data->transform.x / draw_data->transform.y));
	draw_data->sprite_height = abs((int)(WIN_HEIGHT
				/ (draw_data->transform.y)));
	draw_data->draw_starty = -draw_data->sprite_height / 2 + WIN_HEIGHT / 2;
	if (draw_data->draw_starty < 0)
		draw_data->draw_starty = 0;
	draw_data->draw_endy = draw_data->sprite_height / 2 + WIN_HEIGHT / 2;
	if (draw_data->draw_endy >= WIN_HEIGHT)
		draw_data->draw_endy = WIN_HEIGHT - 1;
	draw_data->sprite_width = abs((int)(WIN_HEIGHT / (draw_data->transform.y)));
	draw_data->draw_startx = -draw_data->sprite_width
		/ 2 + draw_data->sprite_screenx;
	if (draw_data->draw_startx < 0)
		draw_data->draw_startx = 0;
	draw_data->draw_endx = draw_data->sprite_width / 2
		+ draw_data->sprite_screenx;
	if (draw_data->draw_endx >= WIN_WIDTH)
		draw_data->draw_endx = WIN_WIDTH - 1;
}

static void	setup_texture_sizes(t_data *data, t_sprite_draw *draw_data)
{
	int					texture;
	t_animated_sprite	current_sprites;
	t_img				current_sprite;

	texture = data->map_sprites[data->sprite_order[draw_data->i]].texture;
	current_sprites = get_animated_sprite(data, texture);
	current_sprite = current_sprites.sprites[current_sprites.current_index];
	draw_data->texture_width = current_sprite.size.x;
	draw_data->texture_height = current_sprite.size.y;
}

void	draw_sprites(t_data *data)
{
	t_sprite_draw	*draw_data;

	sort_sprites(data);
	draw_data = malloc(sizeof(t_sprite_draw));
	draw_data->i = -1;
	while (++(draw_data->i) < data->sprites_count)
	{
		setup_texture_sizes(data, draw_data);
		draw_data->pos.x = data->map_sprites[data->sprite_order[draw_data->i]]
			.pos.x - data->player.pos.x;
		draw_data->pos.y = data->map_sprites[data->sprite_order[draw_data->i]]
			.pos.y - data->player.pos.y;
		draw_data->inv_det = 1.0 / (data->camera_plane.x * data->player.dir.y
				- data->player.dir.x * data->camera_plane.y);
		draw_data->transform = new_vector(draw_data->inv_det
				* (data->player.dir.y * draw_data->pos.x
					- data->player.dir.x * draw_data->pos.y),
				draw_data->inv_det * (-data->camera_plane.y * draw_data->pos.x
					+ data->camera_plane.x * draw_data->pos.y));
		setup_data(draw_data);
		draw_sprite(data, *draw_data);
	}
	free(draw_data);
}
