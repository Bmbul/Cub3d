#include "cub3d.h"

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
