#include "../includes/cub3d.h"

void	setup_player(t_data *data, int row, int col)
{
	if (data->map[row][col] == 'N')
		data->player.dir = new_vector(-1, 0);
	else if (data->map[row][col] == 'E')
		data->player.dir = new_vector(0, 1);
	else if (data->map[row][col] == 'W')
		data->player.dir = new_vector(0, -1);
	else if (data->map[row][col] == 'S')
		data->player.dir = new_vector(1, 0);
	data->player.pos = new_vector(col, row);
	data->camera_plane = new_vector(-0.66 * data->player.dir.y,
			0.66 * data->player.dir.x);
}

void	update(t_data *data)
{
	(void) data;
	if (should_move(data))
	{
		move_player(data);
		draw(data);
	}
}

void	start_game(t_data *data)
{
	draw(data);
	mlx_hook(data->window, 2, 1L << 0, (void *)key_press, data);
	mlx_hook(data->window, 3, 1L << 1, (void *)key_release, data);
	mlx_hook(data->window, 17, 1L << 0, (void *)exit_game, data);
	mlx_loop_hook(data->mlx, (void *)update, data);
	mlx_loop(data->mlx);
}
