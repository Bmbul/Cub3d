# include "cub3d.h"

void	exit_game(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	free_data(data);
	mlx_destroy_window(data->mlx, data->window);
	exit(0);
}

void	start_game(t_data	*data)
{
	//mlx_hook(data->window, 2, 1L << 2, (void *)add_listeners, data);
	mlx_hook(data->window, 17, 0, (void *)exit_game, data);
	mlx_loop(data->mlx);
}
