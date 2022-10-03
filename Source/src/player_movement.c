# include "cub3d.h"

void	move_forward(t_data *data, int dir)
{
	t_text	map;

	map = data->map;
	printf("player pos before: %f %f\n", data->player.pos.x, data->player.pos.y);
	if (map[(int)(data->player.pos.x + dir
			* data->player.dir.x * MOVEMENT_SPEED)]
		[(int)(data->player.pos.y)] == '0')
	{
		printf("inside first if\n");
		data->player.pos.x = data->player.pos.x
			+ data->player.dir.x * dir * MOVEMENT_SPEED;
	}
	if (map[(int)(data->player.pos.x)][(int)(data->player.pos.y
		+ dir * data->player.dir.y * MOVEMENT_SPEED)] == '0')
	{
		data->player.pos.y = data->player.pos.y
			+ dir * data->player.dir.y * MOVEMENT_SPEED;
		printf("inside second if\n");
	}
	printf("player pos after: %f %f\n", data->player.pos.x, data->player.pos.y);
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
	if (k_code == RIGHT_ARROW)
		rotate(data, 1);
	else if (k_code == LEFT_ARROW)
		rotate(data, -1);
}
