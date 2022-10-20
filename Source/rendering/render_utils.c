#include "cub3d.h"

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

double	perp_wall_dist(t_draw draw)
{
	if (draw.side == 0)
		return (draw.side_dist.x - draw.delta_dist.x);
	else
		return (draw.side_dist.y - draw.delta_dist.y);
}

double	wall_x(t_data *data, t_draw draw)
{
	double	wallx;

	if (draw.side == 0)
		wallx = data->player.pos.y + perp_wall_dist(draw) * draw.ray.y;
	else
		wallx = data->player.pos.x + perp_wall_dist(draw) * draw.ray.x;
	wallx -= floor((wallx));
	return (wallx);
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
