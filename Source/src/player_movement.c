/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:09:58 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:09:59 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_bool	can_move(t_data *data, t_vector mov_dir, t_tuple inp_dir)
{
	char	map_letter;

	map_letter = data->map[(int)(data->player.pos.x + inp_dir.x
			* mov_dir.x * MOVEMENT_SPEED)]
	[(int)(data->player.pos.y + inp_dir.y
			* mov_dir.y * MOVEMENT_SPEED)];
	return (!contains("123", map_letter));
}

void	move_forward(t_data *data, int dir)
{
	if (can_move(data, data->player.dir, new_tuple(dir, 0)))
	{
		data->player.pos.x = data->player.pos.x
			+ data->player.dir.x * dir * MOVEMENT_SPEED;
	}
	if (can_move(data, data->player.dir, new_tuple(0, dir)))
	{
		data->player.pos.y = data->player.pos.y
			+ dir * data->player.dir.y * MOVEMENT_SPEED;
	}
}

void	move_side(t_data *data, int dir)
{
	t_text		map;
	t_vector	move_dir;

	move_dir = new_vector(-data->player.dir.y, data->player.dir.x);
	map = data->map;
	if (can_move(data, move_dir, new_tuple(dir, 0)))
	{
		data->player.pos.x = data->player.pos.x
			+ move_dir.x * dir * MOVEMENT_SPEED;
	}
	if (can_move(data, move_dir, new_tuple(0, dir)))
	{
		data->player.pos.y = data->player.pos.y
			+ dir * move_dir.y * MOVEMENT_SPEED;
	}
}

void	rotate(t_data *data, int dir)
{
	t_vector	old_dir;
	t_vector	old_plane;

	old_dir = data->player.dir;
	old_plane = data->camera_plane;
	data->player.dir.x = old_dir.x * cos(SENSITIVITY * dir)
		- old_dir.y * sin(SENSITIVITY * dir);
	data->player.dir.y = old_dir.x * sin(SENSITIVITY * dir)
		+ old_dir.y * cos(SENSITIVITY * dir);
	data->camera_plane.x = old_plane.x * cos(SENSITIVITY * dir)
		- old_plane.y * sin(SENSITIVITY * dir);
	data->camera_plane.y = old_plane.x * sin(SENSITIVITY * dir)
		+ old_plane.y * cos(SENSITIVITY * dir);
}

void	move_player(t_data *data)
{
	if (data->mov_input.x)
		move_side(data, -data->mov_input.x);
	if (data->mov_input.y)
		move_forward(data, data->mov_input.y);
	if (data->mov_input.rot)
		rotate(data, -data->mov_input.rot);
}
