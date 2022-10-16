#include "../includes/cub3d.h"

double	camera_x(int col)
{
	return (2 * col / (double)WIN_WIDTH - 1);
}

t_vector	init_ray(t_data *data, int col)
{
	t_vector	ray;

	ray.x = data->player.dir.x + data->camera_plane.x * camera_x(col);
	ray.y = data->player.dir.y + data->camera_plane.y * camera_x(col);
	return (ray);
}

double	perpWallDist(t_draw draw)
{
	if (draw.side == 0)
		return (draw.side_dist.x - draw.delta_dist.x);
	else
		return (draw.side_dist.y - draw.delta_dist.y);
}

double	wallX(t_data *data, t_draw draw)
{
	double	wallX;

	if (draw.side == 0)
		wallX = data->player.pos.y + perpWallDist(draw) * draw.ray.y;
	else
		wallX = data->player.pos.x + perpWallDist(draw) * draw.ray.x;
	wallX -= floor((wallX));
	return (wallX);
}

t_vector	init_delta_dist(t_draw draw)
{
	t_vector	delta_dist;

	if (draw.ray.x == 0)
		delta_dist.x = 1e30;
	else
		delta_dist.x = fabs(1 / draw.ray.x);
	if (draw.ray.y == 0)
		delta_dist.y = 1e30;
	else
		delta_dist.y = fabs(1 / draw.ray.y);
	return (delta_dist);
}

t_vector	init_side_dist(t_data *data, t_draw draw)
{
	t_vector	side_dist;

	if (draw.ray.x < 0)
		side_dist.x = (data->player.pos.x - draw.map.x) * draw.delta_dist.x;
	else
		side_dist.x = (draw.map.x + 1.0 - data->player.pos.x) * \
				draw.delta_dist.x;
	if (draw.ray.y < 0)
		side_dist.y = (data->player.pos.y - draw.map.y) * draw.delta_dist.y;
	else
		side_dist.y = (draw.map.y + 1.0 - data->player.pos.y) * \
				draw.delta_dist.y;
	return (side_dist);
}

t_tuple	init_step(t_draw draw)
{
	t_tuple	step;

	if (draw.ray.x < 0)
		step.x = -1;
	else
		step.x = 1;
	if (draw.ray.y < 0)
		step.y = -1;
	else
		step.y = 1;
	return (step);
}

void	init_side_hit(t_data *data, t_draw *draw)
{
	while (draw->hit == 0)
	{
		if (draw->side_dist.x < draw->side_dist.y)
		{
			draw->side_dist.x += draw->delta_dist.x;
			draw->map.x += draw->step.x;
			draw->side = 0;
		}
		else
		{
			draw->side_dist.y += draw->delta_dist.y;
			draw->map.y += draw->step.y;
			draw->side = 1;
		}
		if (data->map[draw->map.x][draw->map.y] == '1')
			draw->hit = 1;
		else if (!contains("0NEWS", data->map[draw->map.x][draw->map.y]))
			add_node(data->drawing_sprites, new_lnode(ft_strdup("2")));
	}
}

int	init_lineHeight(t_draw draw)
{
	return ((int)(WIN_HEIGHT / perpWallDist(draw)));
}

int	init_texX(t_data *data, t_draw draw)
{
	int	texX;

	texX = (int)(wallX(data, draw) * (double)TEXT_WIDTH);
	if (draw.side == 0 && draw.ray.x > 0)
		texX = TEXT_WIDTH - texX + 1; // blue texture
	if (draw.side == 0 && draw.ray.x > 0)
		texX = TEXT_WIDTH - texX + 2 + 64; // yellow texture
	if (draw.side == 1 && draw.ray.y < 0)
		texX = TEXT_WIDTH - texX + 1 + 128; // grey texture
	if (draw.side == 1 && draw.ray.y > 0)
		texX = TEXT_WIDTH - texX + 2 + 192; // brown texture
	return (texX);
}

int	init_drawStart(t_draw draw)
{
	int	drawStart;

	drawStart = -draw.lineHeight / 2;
	if (drawStart < 0)
		drawStart = 0;
	return (drawStart);
}

int	init_drawEnd(t_draw draw)
{
	int	drawEnd;

	drawEnd = draw.lineHeight / 2 + WIN_HEIGHT / 2;
	if (drawEnd >= WIN_HEIGHT)
		drawEnd = WIN_HEIGHT - 1;
	return (drawEnd);
}

double	init_ratio(t_draw draw)
{
	return (1.0 * TEXT_HIGHT / draw.lineHeight);
}

double	init_texPos(t_draw draw)
{
	if ((-draw.lineHeight / 2) < 0)
		return ((0 - WIN_HEIGHT / 2 + draw.lineHeight / 2) * draw.ratio);
	else
		return ((-draw.lineHeight / 2 - WIN_HEIGHT / 2 + draw.lineHeight / 2) * \
			draw.ratio);
}

t_draw	init_draw(t_data *data, int col)
{
	t_draw	draw;

	draw.hit = 0;
	draw.ray = init_ray(data, col);
	draw.map = vector_to_tuple(data->player.pos);
	draw.delta_dist = init_delta_dist(draw);
	draw.side_dist = init_side_dist(data, draw);
	draw.step = init_step(draw);
	init_side_hit(data, &draw);
	draw.lineHeight = init_lineHeight(draw);
	draw.ceiling_size = -draw.lineHeight / 2 + WIN_HEIGHT / 2;
	draw.drawStart = init_drawStart(draw);
	draw.drawEnd = init_drawEnd(draw);
	draw.texX = init_texX(data, draw);
	draw.ratio = init_ratio(draw);
	draw.texPos = init_texPos(draw);
	return (draw);
}

void	draw(t_data *data)
{
	int		col;
	t_draw	draw;

	col = -1;
	free_list_nodes(data->drawing_sprites);
	while (++col < WIN_WIDTH)
	{
		draw = init_draw(data, col);
		vertical_line(data, col, draw);
	}
	draw_sprites(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->window,
		data->frame.img_ptr, 0, 0);
}

void	draw_ceiling(t_data *data, t_draw draw, int col)
{
	int	row;

	row = -1;
	while (++row < draw.ceiling_size)
		*(unsigned int *)(data->frame.data_addr
				+ (row * data->frame.size_line + col
					* (data->frame.bits_per_pixel / 8)))
			= get_color(*(data->ceiling_color));
}

void	vertical_line(t_data *data, int col, t_draw draw)
{
	int				row;
	int				texY;
	unsigned int	color_hex;

	row = -1;
	while (++row < WIN_HEIGHT)
	{
		texY = (int)draw.texPos & (64 - 1);
		draw.texPos += draw.ratio;
		if (row >= draw.drawStart && row <= draw.drawEnd)
			color_hex = data->textures->north.texture[texY + 64 * draw.texX];
		else if (row > WIN_HEIGHT / 2)
			color_hex = get_color(*(data->floor_color));
		else
			color_hex = get_color(*(data->ceiling_color));
		*(unsigned int *)(data->frame.data_addr
				+ (row * data->frame.size_line + col
					* (data->frame.bits_per_pixel / 8)))
			= color_hex;
	}
	draw_ceiling(data, draw, col);
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
