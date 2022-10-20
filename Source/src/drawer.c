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
		texX = TEXT_WIDTH - texX - 1;
	if (draw.side == 1 && draw.ray.y < 0)
		texX = TEXT_WIDTH - texX - 1;
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
	while (++col < WIN_WIDTH)
	{
		draw = init_draw(data, col);
		data->z_buffer[col] = perpWallDist(draw);
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
	unsigned int	hex;

	row = -1;
	while (++row < WIN_HEIGHT)
	{
		texY = (int)draw.texPos & (64 - 1);
		draw.texPos += draw.ratio;
		if (row >= draw.drawStart && row <= draw.drawEnd)
		{
			if (draw.side == 0 && draw.ray.x > 0)
				hex = data->textures->south.texture[texY + 64 * draw.texX];
			else if (draw.side == 0 && draw.ray.x < 0)
				hex = data->textures->north.texture[texY + 64 * draw.texX];
			else if (draw.side == 1 && draw.ray.y < 0)
				hex = data->textures->west.texture[texY + 64 * draw.texX];
			else if (draw.side == 1 && draw.ray.y > 0)
				hex = data->textures->east.texture[texY + 64 * draw.texX];
		}
		else if (row > WIN_HEIGHT / 2)
			hex = get_color(*(data->floor_color));
		else
			hex = get_color(*(data->ceiling_color));
		*(unsigned int *)(data->frame.data_addr
				+ (row * data->frame.size_line + col
					* (data->frame.bits_per_pixel / 8)))
			= hex;
	}
	draw_ceiling(data, draw, col);
}

void sort_sprites(t_data *data)
{
	int		i;
	t_order	*sprites;

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

	texture_width = 35;
	texture_height = 50;
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
	sort_sprites(data);
	i = -1;
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
		col = draw_startx - 1;
		while (++col < draw_endx)
		{
        	int tex_x = (int)(256 * (col - (-sprite_width / 2
				+ sprite_screenx)) * texture_width / sprite_width) / 256;
			if (transform.y > 0 && transform.y < data->z_buffer[col])
			{
				row = draw_starty - 1;
				while (++row < draw_endy)
				{
					int d = (row) * 256 - WIN_HEIGHT * 128 + sprite_height * 128;
					int tex_y = ((d * texture_height) / sprite_height) / 256;
					unsigned int color = get_animated_sprite_color(data->map_sprites[i].texture, data, tex_x, tex_y);
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

void    draw_minimap(t_data *data)
{
	int				ver_block;
	int				hor_block;
	int				ver_pixel;
	int				hor_pixel;
	int				ver_scale;
	int				hor_scale;
	unsigned int	color;

	hor_block = -MINI_SIZE;
	ver_pixel = WIN_HEIGHT - MINI_SCALE * MINI_SIZE * 2 - MAP_OFFSET;
	while (hor_block < MINI_SIZE)
	{
		ver_scale = 0;
		while (ver_scale < MINI_SCALE)
		{
			hor_pixel = MAP_OFFSET;
			ver_block = -MINI_SIZE;
			while (ver_block < MINI_SIZE)
			{
				hor_scale = 0;
				while (hor_scale < MINI_SCALE)
				{
					if ((data->player.pos.x + hor_block) < 0 || \
						(data->player.pos.x + hor_block) >= data->map_height || \
						(data->player.pos.y + ver_block) < 0 || \
						(data->player.pos.y + ver_block) >= data->map_width)
					{
						color = 0x0000FF;
					}
					else
					{
						if (data->map[(int)data->player.pos.x + hor_block][(int)data->player.pos.y + ver_block] != '0')
							color = 0x433BDE;
						if (hor_block == 0 && ver_block == 0)
							color = 0x00FF00;
						else if (data->map[(int )data->player.pos.x + hor_block][(int )data->player.pos.y + ver_block] == '1')
							color = 0xDEDEDE;
						else if (data->map[(int )data->player.pos.x + hor_block][(int )data->player.pos.y + ver_block] == '2')
							color = 0xFF00FF;
						else
							color = 0x433BDE;
					}
					*(unsigned int *)(data->frame.data_addr
							+ (ver_pixel * data->frame.size_line + hor_pixel
								* (data->frame.bits_per_pixel / 8)))
						= color;
					hor_pixel++;
					hor_scale++;
				}
				ver_block++;
			}
			ver_pixel++;
			ver_scale++;
		}
		hor_block++;
	}
}
