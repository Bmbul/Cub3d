/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:09:54 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:09:55 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	setup_player(t_data *data, int row, int col)
{
	if (data->map[row][col] == 'N')
		data->player.dir = new_vector(-1, 0.01);
	else if (data->map[row][col] == 'E')
		data->player.dir = new_vector(0.01, 1);
	else if (data->map[row][col] == 'W')
		data->player.dir = new_vector(0.01, -1);
	else if (data->map[row][col] == 'S')
		data->player.dir = new_vector(1, 0.01);
	data->player.pos = new_vector(col, row);
	data->camera_plane = new_vector(0.66 * data->player.dir.y,
			-0.66 * data->player.dir.x);
}

void	update_animations(t_data *data)
{
	int					i;
	t_animated_sprite	*s;

	i = -1;
	while (++i < SPRITES_COUNT)
	{
		s = data->a_sprites + i;
		if (s->frames_count == 1)
			continue ;
		s->current_frame++;
		if (s->current_frame >= s->frames_count)
		{
			s->current_index = (s->current_index + 1) % s->sprites_count;
			s->current_frame = 0;
		}
	}
}

void	update(t_data *data)
{
	if (should_move(data))
		move_player(data);
	update_animations(data);
	draw(data);
}

void	start_game(t_data *data)
{
	draw(data);
	mlx_hook(data->window, 6, 1L << 6, (void *)mouse_move, data);
	mlx_hook(data->window, 2, 1L << 0, (void *)key_press, data);
	mlx_hook(data->window, 3, 1L << 1, (void *)key_release, data);
	mlx_hook(data->window, 17, 1L << 0, (void *)exit_game, data);
	mlx_loop_hook(data->mlx, (void *)update, data);
	mlx_loop(data->mlx);
}
