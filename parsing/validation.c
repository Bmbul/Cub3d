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
		//printf("validating %d\n", i);
		if (!has_extention(data->texture_paths[i], "xpm"))
		{
			printf("Does not have right extention: %s\n", data->texture_paths[i]);
			return (FALSE);
		}
		fd = open(data->texture_paths[i], O_RDONLY);
		if (fd == -1)
			return (FALSE);
		printf("validated %d\n", i);
		close(fd);
	}
	return (TRUE);
}

t_bool	validate_map(t_data *data)
{
	(void)data;
	printf("validating map\n");
	return (FALSE);
	// int i;

	// i = -1;
	// while (data->map[++i])
	// {
	// 	if ()
	// }
}
