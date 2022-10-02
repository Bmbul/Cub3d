# include "cub3d.h"


void	move_forward(t_data *data, int dir)
{
	t_text	map;

	map = data->map;
	printf("player pos before: %f %f\n", data->player.pos.x, data->player.pos.y);
	if (map[(int)(data->player.pos.x + dir * data->player.dir.x * MOVEMENT_SPEED)]
		[(int)(data->player.pos.y)] == '0')
	{
		printf("inside first if\n");
		data->player.pos.x = data->player.pos.x + data->player.dir.x * dir * MOVEMENT_SPEED;
	}
	if(map[(int)(data->player.pos.x)][(int)(data->player.pos.y
		+ dir * data->player.dir.y * MOVEMENT_SPEED)] == '0')
	{
		data->player.pos.y = data->player.pos.y + dir * data->player.dir.y * MOVEMENT_SPEED;
		printf("inside second if\n");
	}
	printf("player pos after: %f %f\n", data->player.pos.x, data->player.pos.y);
}

void	move_player(int k_code, t_data *data)
{
	if (k_code == KEY_W || k_code == KEY_A
	|| k_code == KEY_S || k_code == KEY_D)
	{
		if (k_code == KEY_W)
			move_forward(data, 1);
		//if (k_code == KEY_A)
		//	pos_change = data->dir.left;
		if (k_code == KEY_S)
			move_forward(data, -1);
		//if (k_code == KEY_D)
		//	pos_change = data->dir.right;
		return ;
	}
	//dir_change = v_inverse(data->player->dir);
	//if (k_code == RIGHT_ARROW)
	//data->player->dir = v_sum(data->player->dir,
	//		s_product(dir_change, SENSITIVITY));
	//else
	//data->player->dir = v_diff(data->player->dir,
	//		s_product(dir_change, SENSITIVITY));
}
