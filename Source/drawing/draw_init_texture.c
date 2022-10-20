#include "cub3d.h"

double	init_tex_pos(t_draw draw)
{
	if ((-draw.line_height / 2) < 0)
		return ((0 - WIN_HEIGHT / 2 + draw.line_height / 2) * draw.ratio);
	else
		return ((-draw.line_height / 2 - WIN_HEIGHT / 2
				+ draw.line_height / 2) * draw.ratio);
}

int	init_tex_x(t_data *data, t_draw draw)
{
	int	tex_x;

	tex_x = (int)(wall_x(data, draw) * (double)TEXT_WIDTH);
	if (draw.side == 0 && draw.ray.x > 0)
		tex_x = TEXT_WIDTH - tex_x - 1;
	if (draw.side == 1 && draw.ray.y < 0)
		tex_x = TEXT_WIDTH - tex_x - 1;
	return (tex_x);
}
