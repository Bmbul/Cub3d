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

void	setup_player(t_data *data, int row, int col)
{
	if (data->map[row][col] == 'N')
		data->player.dir = new_vector(0, -1);
	else if (data->map[row][col] == 'E')
		data->player.dir = new_vector(1, 0);
	else if (data->map[row][col] == 'W')
		data->player.dir = new_vector(-1, 0);
	else if (data->map[row][col] == 'S')
		data->player.dir = new_vector(0, 1);
	data->player.pos = new_vector(col, row);
	data->camera_plane = new_vector(0, 0.66);
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
	// while (data->textures->east.data_addr[++idx])
	// 	printf("texture[%d]: %d\n", idx, data->textures->east.data_addr[idx]);
	printf("player pos before: %f %f\n", data->player.pos.x, data->player.pos.y);
	draw(data);
	mlx_hook(data->window, 2, 1L << 0, (void *)key_press, data);
	mlx_hook(data->window, 3, 1L << 1, (void *)key_release, data);
	mlx_hook(data->window, 17, 1L << 0, (void *)exit_game, data);
	mlx_loop_hook(data->mlx, (void *)update, data);
	mlx_loop(data->mlx);
}
