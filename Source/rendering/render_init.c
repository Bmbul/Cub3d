/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:09:33 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:09:34 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_draw_start(t_draw draw)
{
	int	draw_start;

	draw_start = -draw.line_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	return (draw_start);
}

int	init_draw_end(t_draw draw)
{
	int	draw_end;

	draw_end = draw.line_height / 2 + WIN_HEIGHT / 2;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	return (draw_end);
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
	draw.line_height = (int)(WIN_HEIGHT / perp_wall_dist(draw));
	draw.ceiling_size = -draw.line_height / 2 + WIN_HEIGHT / 2;
	draw.draw_start = init_draw_start(draw);
	draw.draw_end = init_draw_end(draw);
	draw.tex_x = init_tex_x(data, draw);
	draw.ratio = 1.0 * TEXT_HIGHT / draw.line_height;
	draw.tex_pos = init_tex_pos(draw);
	return (draw);
}
