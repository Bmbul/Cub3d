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

t_bool	validate_input_paths(t_data *data)
{
	t_node	*current;

	if (data->input_dict->count != 6)
		return (FALSE);
	while (current)
	{
		if (!add_to_data(current, data))
			return (FALSE);
		current = current->next;
	}
	if (!data->textures->east || !data->textures->west
		|| !data->textures->north || !data->textures->south
		|| !data->floor_color || !data->ceiling_color)
		return (FALSE);
	return (TRUE);
}

t_bool	validate_map(t_data *data)
{
	int i;

	i = -1;
	while (data->map[++i])
	{
		if ()
	}
}
