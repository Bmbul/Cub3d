#include "cub3d.h"

int	tex_y(t_sprite_draw draw_data, int row)
{
	int	d;

	d = (row) * 256 - WIN_HEIGHT * 128 + draw_data.sprite_height * 128;
	return (((d * draw_data.texture_height) / draw_data.sprite_height) / 256);
}

int	tex_x(t_sprite_draw draw_data, int col)
{
	return ((int)(256 * (col - (-draw_data.sprite_width / 2
				+ draw_data.sprite_screenx)) * draw_data.texture_width
		/ draw_data.sprite_width) / 256);
}
