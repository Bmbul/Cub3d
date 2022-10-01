# include "cub3d.h"

void	move_player(int k_code, t_data *data)
{
	(void) k_code;
	(void) data;
	// t_vector	pos_change;
	// t_vector	dir_change;

	// if (k_code == KEY_W || k_code == KEY_A
	// 	|| k_code == KEY_S || k_code == KEY_D)
	// {
	// 	if (k_code == KEY_W)
	// 		pos_change = data->dir.up;
	// 	if (k_code == KEY_A)
	// 		pos_change = data->dir.left;
	// 	if (k_code == KEY_S)
	// 		pos_change = data->dir.down;
	// 	if (k_code == KEY_D)
	// 		pos_change = data->dir.right;
	// 	data->player->pos = v_sum(data->player->pos, pos_change);
	// 	return ;
	// }
	// dir_change = v_inverse(data->player->dir);
	// if (k_code == RIGHT_ARROW)
	// 	data->player->dir = v_sum(data->player->dir,
	// 			s_product(dir_change, SENSITIVITY));
	// else
	// 	data->player->dir = v_diff(data->player->dir,
	// 			s_product(dir_change, SENSITIVITY));
}
