# include "cub3d.h"

t_bool	validate_input_file(t_string input)
{
	int	fd;

	fd = open(input, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	close(fd);
	return (TRUE);
}

t_bool	validate_arguments(t_data *data)
{
	t_node	*current;

	if (data->input_dict->count != 6)
		return (FALSE);
	current = data->input_dict->head;
	while (current)
	{
		if (!add_to_data(current, data))
		{
			printf("could not add %s - %s", current->key, current->value);
			return (FALSE);
		}
		current = current->next;
	}
	if (!validate_texture_paths(data))
	{
		print_error("Did not validate texture paths\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	validate_texture_paths(t_data *data)
{
	int	fd;
	int	i;

	i = -1;
	while (++i < TEXTURES_COUNT)
	{
		printf("validating %d\n", i);
		if (!has_extention(data->texture_paths[i], "xpm"))
		{
			printf("Does not have right extention: %s\n", data->texture_paths[i]);
			return (FALSE);
		}
		fd = open(data->texture_paths[i], O_RDONLY);
		if (fd == -1)
			return (FALSE);
		//printf("validated %d\n", i);
		close(fd);
	}
	return (TRUE);
}

t_bool	not_surrounded_by_walls(t_data *data, int row, int col)
{
	t_text	map;

	map = data->map;
	if (row * col == 0 || row == data->map_height - 1
		|| col == data->map_width - 1)
		return (TRUE);
	if (map[row - 1][col] == EMPTY || map[row + 1][col] == EMPTY
		|| map[row][col - 1] == EMPTY || map[row][col + 1] == EMPTY
		|| map[row - 1][col - 1] == EMPTY || map[row - 1][col + 1] == EMPTY
		|| map[row + 1][col - 1] == EMPTY || map[row + 1][col + 1] == EMPTY)
		return (TRUE);
	return (FALSE);
}

t_bool	validate_map(t_data *data)
{
	int	row;
	int	col;

	row = -1;
	if (!data->map || !data->map_height || !data->map_width)
		return (FALSE);
	while (++row < data->map_height)
	{
		col = -1;
		while (++col < data->map_width)
		{
			if (data->map[row][col] == GROUND)
				if (not_surrounded_by_walls(data, row, col))
					return (FALSE);
			//printf("validated map[%d][%d] = %c\n", row, col, data->map[row][col]);
		}
	}
	return (TRUE);
}
