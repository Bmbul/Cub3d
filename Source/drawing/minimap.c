#include "cub3d.h"

void	draw_minimap(t_data *data)
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

