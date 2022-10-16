#include "../includes/cub3d.h"

void	exit_game(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	mlx_destroy_window(data->mlx, data->window);
	free_data(data);
	exit(0);
}

void	key_press(int key_code, t_data *data)
{
	if (key_code == KEY_ESC)
		exit_game(data);
	if (!is_movement_key(key_code))
		return ;
	if (key_code == KEY_W)
		data->key_map.w = 1;
	else if (key_code == KEY_A)
		data->key_map.a = 1;
	else if (key_code == KEY_S)
		data->key_map.s = 1;
	else if (key_code == KEY_D)
		data->key_map.d = 1;
	else if (key_code == LEFT_ARROW)
		data->key_map.left = 1;
	else if (key_code == RIGHT_ARROW)
		data->key_map.right = 1;
}

void	key_release(int key_code, t_data *data)
{
	if (!is_movement_key(key_code))
		return ;
	if (key_code == KEY_W)
		data->key_map.w = 0;
	else if (key_code == KEY_A)
		data->key_map.a = 0;
	else if (key_code == KEY_S)
		data->key_map.s = 0;
	else if (key_code == KEY_D)
		data->key_map.d = 0;
	else if (key_code == LEFT_ARROW)
		data->key_map.left = 0;
	else if (key_code == RIGHT_ARROW)
		data->key_map.right = 0;
}
