#include "cub3d.h"

t_bool	is_movement_key(int k_code)
{
	if (!(k_code == KEY_W || k_code == KEY_A
			|| k_code == KEY_S || k_code == KEY_D
			|| k_code == LEFT_ARROW || k_code == RIGHT_ARROW))
		return (FALSE);
	return (TRUE);
}

t_bool	should_move(t_data *data)
{
	if (data->key_map.w == 1 && data->key_map.s == 0)
		data->mov_input.y = 1;
	else if (data->key_map.w == 0 && data->key_map.s == 1)
			data->mov_input.y = -1;
	else
		data->mov_input.y = 0;
	if (data->key_map.d == 1 && data->key_map.a == 0)
		data->mov_input.x = 1;
	else if (data->key_map.d == 0 && data->key_map.a == 1)
			data->mov_input.x = -1;
	else
		data->mov_input.x = 0;
	if (data->key_map.right == 1 && data->key_map.left == 0)
		data->mov_input.rot = 1;
	else if (data->key_map.right == 0 && data->key_map.left == 1)
			data->mov_input.rot = -1;
	else
		data->mov_input.rot = 0;
	return (data->mov_input.x || data->mov_input.y || data->mov_input.rot);
}
