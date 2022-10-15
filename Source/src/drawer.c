#include "../includes/cub3d.h"

void	draw(t_data *data)
{
	int			i;
	double		camera_x;
	t_vector	ray;
	t_tuple		map;
	t_vector	delta_dist;
	t_vector	side_dist;
	double 		perpWallDist;
	t_tuple		step;
	int			hit;
	int			side;

	i = -1;
	free_list_nodes(data->drawing_sprites);
	while (++i < WIN_WIDTH)
	{
		hit = 0;
		camera_x = 2 * i / (double)WIN_WIDTH - 1;
		ray.x = data->player.dir.x + data->camera_plane.x * camera_x;
		ray.y = data->player.dir.y + data->camera_plane.y * camera_x;
		map = vector_to_tuple(data->player.pos);
		if (ray.x == 0)
			delta_dist.x = 1e30;
		else
			delta_dist.x = fabs(1 / ray.x);
		if (ray.y == 0)
			delta_dist.y = 1e30;
		else
			delta_dist.y = fabs(1 / ray.y);
		if (ray.x < 0)
		{
			step.x = -1;
			side_dist.x = (data->player.pos.x - map.x) * delta_dist.x;
		}
		else
		{
			step.x = 1;
			side_dist.x = (map.x + 1.0 - data->player.pos.x) * delta_dist.x;
		}
		if (ray.y < 0)
		{
			step.y = -1;
			side_dist.y = (data->player.pos.y - map.y) * delta_dist.y;
		}
		else
		{
			step.y = 1;
			side_dist.y = (map.y + 1.0 - data->player.pos.y) * delta_dist.y;
		}
		while (hit == 0)
		{
			if (side_dist.x < side_dist.y)
			{
				side_dist.x += delta_dist.x;
				map.x += step.x;
				side = 0;
			}
			else
			{
				side_dist.y += delta_dist.y;
				map.y += step.y;
				side = 1;
			}
			if (data->map[map.x][map.y] == '1')
				hit = 1;
			else if (!contains("0NEWS", data->map[map.x][map.y]))
				add_node(data->drawing_sprites, new_lnode(ft_strdup("2")));
			// modify the code so the every node can be added only once
			// add position data to the node
			// most probably you need new struct
			// write new chardup
			// determine how textures should be got from letters
		}
		if (side == 0)
			perpWallDist = side_dist.x - delta_dist.x;
		else
			perpWallDist = side_dist.y - delta_dist.y;
		int	lineHeight;
		lineHeight = (int)(WIN_HEIGHT / perpWallDist);
		int	drawStart;
		drawStart = -lineHeight / 2;
		int ceiling_size = -lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int	drawEnd;
		drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;
		double wallX;
		if (side == 0)
			wallX = data->player.pos.y + perpWallDist * ray.y;
		else
			wallX = data->player.pos.x + perpWallDist * ray.x;
		wallX -= floor((wallX));

		int	texWidth = 64;
		int texHeight = 64;
		int texX = (int)(wallX * (double)texWidth);
		if(side == 0 && ray.x > 0)
			texX = texWidth - texX - 1;
		if(side == 0 && ray.x > 0)
			texX = texWidth - texX - 1 + 64;
		if(side == 1 && ray.y < 0)
			texX = texWidth - texX - 1 + 128;
		if(side == 1 && ray.y > 0)
			texX = texWidth - texX - 1 + 192;

		double step = 1.0 * texHeight / lineHeight;
		double texPos = (drawStart - WIN_HEIGHT / 2 + lineHeight / 2) * step;
		// if(side == 0 && ray.x > 0)
		// 	texPos += 4;
		// if(side == 1 && ray.y < 0)
		// 	texPos += 8;
		// if(side == 1 && ray.y > 0)
		// 	texPos += 12;
		vertical_line(data, i, drawStart % WIN_HEIGHT, drawEnd % WIN_HEIGHT, texX, texPos, step, ceiling_size);
		data->z_buffer[i] = perpWallDist;
	}
	draw_sprites(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->window,
		data->frame.img_ptr, 0, 0);
}

void	vertical_line(t_data *data, int i, int draw_start,
				int draw_end, int texX, double texPos, double step, int ceiling_size)
{
	int				col;
	int				tex_y;
	unsigned int	color_hex;

	col = -1;
	while (++col < WIN_HEIGHT)
	{
		tex_y = (int)texPos & (64 - 1);
		texPos += step;
		if (col >= draw_start && col <= draw_end)
			color_hex = data->textures->north.texture[tex_y + 64 * texX];
		else if (col > WIN_HEIGHT / 2)
			color_hex = get_color(*(data->floor_color));
		else
			color_hex = get_color(*(data->ceiling_color));
		*(unsigned int *)(data->frame.data_addr
				+ (col * data->frame.size_line + i
					* (data->frame.bits_per_pixel / 8)))
			= color_hex;
	}
	col = -1;
	while (++col < ceiling_size)
		*(unsigned int *)(data->frame.data_addr
				+ (col * data->frame.size_line + i
					* (data->frame.bits_per_pixel / 8)))
			= get_color(*(data->ceiling_color));
}

// // void sort_sprites(int * order, double * dist, int amount)
// // {
// //   std::vector<std::pair<double, int>> sprites(amount);
// //   for(int i = 0; i < amount; i++) {
// //     sprites[i].first = dist[i];
// //     sprites[i].second = order[i];
// //   }
// //   std::sort(sprites.begin(), sprites.end());
// //   // restore in reverse order to go from farthest to nearest
// //   for(int i = 0; i < amount; i++) {
// //     dist[i] = sprites[amount - i - 1].first;
// //     order[i] = sprites[amount - i - 1].second;
// //   }
// // }

// void sort_sprites(t_data *data)
// {
//   std::vector<std::pair<double, int>> sprites(amount);
//   for(int i = 0; i < amount; i++) {
//     sprites[i].first = dist[i];
//     sprites[i].second = order[i];
//   }
//   std::sort(sprites.begin(), sprites.end());
//   // restore in reverse order to go from farthest to nearest
//   for(int i = 0; i < amount; i++) {
//     dist[i] = sprites[amount - i - 1].first;
//     order[i] = sprites[amount - i - 1].second;
//   }
// }

void	draw_sprites(t_data *data)
{
	int			i;
	int			row;
	int			col;
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	int			sprite_screenx;
	int			sprite_height;
	t_vector	transform;
	int			texture_width;
	int			texture_height;

	texture_width = 64;
	texture_height = 64;
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
    // sort_sprites(data);
	i = -1;
	printf("sprites count : %d\n", data->sprites_count);
	while (++i < data->sprites_count)
	{
		sprite_x = data->map_sprites[data->sprite_order[i]].pos.x
			- data->player.pos.x;
		sprite_y = data->map_sprites[data->sprite_order[i]].pos.y
			- data->player.pos.y;
		inv_det = 1.0 / (data->camera_plane.x * data->player.dir.y
				- data->player.dir.x * data->camera_plane.y);
		transform = new_vector(inv_det * (data->player.dir.y
					* sprite_x
					- data->player.dir.x * sprite_y),
				inv_det * (-data->camera_plane.y * sprite_x
					+ data->camera_plane.x * sprite_y));
		sprite_screenx = (int)((WIN_WIDTH / 2)
				* (1 + transform.x / transform.y));
		sprite_height = abs((int)(WIN_HEIGHT / (transform.y)));
    	int draw_starty = -sprite_height / 2 + WIN_HEIGHT / 2;
		if (draw_starty < 0)
			draw_starty = 0;
      	int draw_endy = sprite_height / 2 + WIN_HEIGHT / 2;
		if (draw_endy >= WIN_HEIGHT)
			draw_endy = WIN_HEIGHT - 1;
      	int sprite_width = abs((int) (WIN_HEIGHT / (transform.y)));
      	int draw_startx = -sprite_width / 2 + sprite_screenx;
		if (draw_startx < 0)
			draw_startx = 0;
		int draw_endx = sprite_width / 2 + sprite_screenx;
		if (draw_endx >= WIN_WIDTH)
			draw_endx = WIN_WIDTH - 1;
		row = draw_startx - 1;
		while (++row < draw_endx)
		{
        	int tex_x = (int)(256 * (row - (-sprite_width / 2
				+ sprite_screenx)) * texture_width / sprite_width) / 256;
			if (transform.y > 0 && transform.y < data->z_buffer[row])
			{
				col = draw_starty - 1;
				while (++col < draw_endy)
				{
					int d = (col) * 256 - WIN_HEIGHT * 128 + sprite_height * 128;
					int tex_y = ((d * texture_height) / sprite_height) / 256;
					unsigned int color = get_img_color(data->sprites[ENEMY_INDEX][0], tex_y, tex_x);
					if ((color & 0x00FFFFFF) != 0)
						*(unsigned int *)(data->frame.data_addr
								+ (row * data->frame.size_line + col
									* (data->frame.bits_per_pixel / 8)))
							= color;
				}
			}
		}
	}
}

void	draw_minimap(t_data *data)
{
	int				idx;
	int				jdx;
	int				m;
	int				n;
	unsigned int	color;

	idx = WIN_HEIGHT - MAP_HEIGHT - MAP_OFFSET;
	while (idx < WIN_HEIGHT - MAP_OFFSET)
	{
		jdx = MAP_OFFSET;
		m = idx - (WIN_HEIGHT - MAP_HEIGHT - MAP_OFFSET);
		m = (m - m % MINI_SCALE) / MINI_SCALE;
		while (jdx < MAP_OFFSET + MAP_WIDTH)
		{
			n = jdx - MAP_OFFSET;
			n = (n - n % MINI_SCALE) / MINI_SCALE;
			if (n == (int)data->player.pos.y && m == (int)data->player.pos.x)
				color = 0xFF0000;
			else if (data->map[m][n] == '1')
				color = 0xDEDEDE;
			else if (data->map[m][n] == '0')
				color = 0x433BDE;
			*(unsigned int *)(data->frame.data_addr
					+ (idx * data->frame.size_line + jdx
						* (data->frame.bits_per_pixel / 8)))
				= color;
			jdx++;
		}
		idx++;
	}
}
