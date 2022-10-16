#include "../includes/cub3d.h"

t_mouse	init_mouse(void)
{
	t_mouse	mouse;

	mouse.hor = WIN_WIDTH / 2;
	mouse.ver = WIN_HEIGHT / 2;
	return (mouse);
}

void	mouse_move(int x, int y, t_data *data)
{
	if (data->mouse.hor != WIN_WIDTH / 2)
	{
		if ((data->mouse.hor - x) < 0)
			rotate(data, 1);
		else
			rotate(data, -1);
		draw(data);
	}
	data->mouse.hor = x;
	data->mouse.ver = y;
}
