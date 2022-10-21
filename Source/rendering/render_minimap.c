/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:09:34 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:47:08 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_minimap	init_minimap_vars(void)
{
	t_minimap	minimap;

	minimap.ver_block = -MINI_SIZE;
	minimap.hor_block = -MINI_SIZE - 1;
	minimap.ver_pixel = WIN_HEIGHT - MINI_SCALE * MINI_SIZE * 2 - MAP_OFFSET;
	minimap.hor_pixel = MAP_OFFSET;
	minimap.ver_scale = 0;
	minimap.hor_scale = 0;
	minimap.color = 0x000000;
	return (minimap);
}

void	minimap_block_coloring(t_data *data, t_minimap *mm)
{
	if (data->map[(int)data->player.pos.x + mm->hor_block]
		[(int)data->player.pos.y + mm->ver_block] != '0')
		mm->color = MINIMAP_OUTER;
	if (mm->hor_block == 0 && mm->ver_block == 0)
		mm->color = MINIMAP_PLAYER;
	else if (data->map[(int )data->player.pos.x + mm->hor_block]
		[(int )data->player.pos.y + mm->ver_block] == '1')
		mm->color = MINIMAP_ONE;
	else if (data->map[(int )data->player.pos.x + mm->hor_block]
		[(int )data->player.pos.y + mm->ver_block] == '2')
		mm->color = MINIMAP_TWO;
	else
		mm->color = MINIMAP_ZERO;
}

void	minimap_coloring(t_data *data, t_minimap mm)
{
	if ((data->player.pos.x + mm.hor_block) < 0 || \
		(data->player.pos.x + mm.hor_block) >= data->map_height || \
		(data->player.pos.y + mm.ver_block) < 0 || \
		(data->player.pos.y + mm.ver_block) >= data->map_width)
	{
		mm.color = 0x0000FF;
	}
	else
	{
		minimap_block_coloring(data, &mm);
	}
	*(unsigned int *)(data->frame.data_addr
			+ (mm.ver_pixel * data->frame.size_line + mm.hor_pixel
				* (data->frame.bits_per_pixel / 8)))
		= mm.color;
}

void	draw_minimap(t_data *data)
{
	t_minimap	mm;

	mm = init_minimap_vars();
	while (++mm.hor_block < MINI_SIZE)
	{
		mm.ver_scale = 0;
		while (mm.ver_scale < MINI_SCALE)
		{
			mm.hor_pixel = MAP_OFFSET;
			mm.ver_block = -MINI_SIZE;
			while (mm.ver_block < MINI_SIZE)
			{
				mm.hor_scale = 0;
				while (mm.hor_scale < MINI_SCALE)
				{
					minimap_coloring(data, mm);
					mm.hor_pixel++;
					mm.hor_scale++;
				}
				mm.ver_block++;
			}
			mm.ver_pixel++;
			mm.ver_scale++;
		}
	}
}
