# include "cub3d.h"

t_data	*data_init(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		print_error_and_exit("Could not create Game Data");
	data->map = NULL;
	data->ceiling_color = NULL;
	data->floor_color = NULL;
	data->mlx = NULL;
	data->window = NULL;
	data->textures = NULL;
	data->texture_paths = malloc(sizeof(t_text));
	data->input_dict = new_dict();
	data->map_list = new_list();
	data->map_height = 0;
	data->map_width = 0;
	return (data);
}

void	mlx_data_init(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 500, 500, "Cub3D");
	textures_init(data);
}

void	print_data(t_data *data)
{
	t_node	*current;
	int		i;

	i = -1;
	if (!data)
		print_error_and_exit("NO DATA\n");
	current = data->input_dict->head;
	while (++i < data->input_dict->count)
	{
		printf("key: %s, value %s\n", current->key, current->value);
		current = current->next;
	}
	//print_color(data->floor_color, "floor");
	//print_color(data->ceiling_color, "ceiling");
	reset_color(1);
}

t_bool	add_to_data(t_node *data_node, t_data *data)
{
	if (ft_strcmp(data_node->key, "NO"))
		data->texture_paths[_NORTH] = ft_strdup(data_node->value);
	else if (ft_strcmp(data_node->key, "EA"))
		data->texture_paths[_EAST] = ft_strdup(data_node->value);
	else if (ft_strcmp(data_node->key, "WE"))
		data->texture_paths[_WEST] = ft_strdup(data_node->value);
	else if (ft_strcmp(data_node->key, "SO"))
		data->texture_paths[_SOUTH] = ft_strdup(data_node->value);
	else if (ft_strcmp(data_node->key, "F"))
	{
		data->floor_color = new_color(data_node->value);
		if (!data->floor_color)
		{
			printf("something went wrong\n");
			return (FALSE);
		}
	}
	else if (ft_strcmp(data_node->key, "C"))
	{
		data->ceiling_color = new_color(data_node->value);
		if (!data->ceiling_color)
			return (FALSE);
	}
	else
	{
		printf("wrong argument\nkey = %s, value = %s\n", data_node->key, data_node->value);
		return (FALSE);
	}
	return (TRUE);
}
