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
			if (data->map[map.x][map.y] != '0')
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (side_dist.x - delta_dist.x);
		else
			perpWallDist = (side_dist.y - delta_dist.y);
		int	lineHeight;
		lineHeight = (int)(WIN_HEIGHT / perpWallDist);
		int	drawStart;
		drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int	drawEnd;
		drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;
		t_color	color;
		color.red = 255;
		color.green = 0;
		color.blue = 0;
		if (side == 1)
			color.red = color.red / 2;
		vertical_line(data, i, drawStart, drawEnd, color);
	}
	mlx_put_image_to_window(data->mlx, data->window,
		data->frame.img_ptr, 0, 0);
}

void	vertical_line(t_data *data, int i, int draw_start,
						int draw_end, t_color color)
{
	int	col;
	int	color_hex;

	col = -1;
	while (++col < WIN_HEIGHT)
	{
		if (col >= draw_start && col <= draw_end)
		{
			// color.green += col;
			color_hex = get_color(color);
		}
		else if (col > WIN_HEIGHT / 2)
			color_hex = get_color(*(data->floor_color));
		else
			color_hex = get_color(*(data->ceiling_color));
		*(unsigned int *)(data->frame.data_addr
				+ (col * data->frame.size_line + i
					* (data->frame.bits_per_pixel / 8)))
			= color_hex;
	}
}

void	fill_black_frame(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			*(unsigned int *)(data->black_frame.data_addr + (i
						* data->black_frame.size_line + j
						* (data->black_frame.bits_per_pixel / 8))) = 0x025215;
		}
	}
}
