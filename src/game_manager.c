# include "cub3d.h"

t_bool	is_movement_key(int k_code)
{
	if (!(k_code == KEY_W || k_code == KEY_A
			|| k_code == KEY_S || k_code == KEY_D)
		|| k_code == LEFT_ARROW || k_code == RIGHT_ARROW)
		return (FALSE);
	
	return (TRUE);
}

void	exit_game(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	free_data(data);
	mlx_destroy_window(data->mlx, data->window);
	exit(0);
}

void	add_listeners(int key_code, t_data *data)
{
	if (key_code == KEY_ESC)
		exit_game(data);
	if (is_movement_key(key_code))
	{
		move_player(data);
		draw_map(data);
	}
}

void	start_game(t_data	*data)
{
	mlx_hook(data->window, 2, 1L << 2, (void *)add_listeners, data);
	mlx_hook(data->window, 17, 0, (void *)exit_game, data);
	mlx_loop(data->mlx);
}
