# include "cub3d.h"

t_direction	setup_directions()
{
	t_direction	direction;

	direction.up = new_vector(1, 0);
	direction.down = new_vector(-1, 0);
	direction.right = new_vector(0, 1);
	direction.left = new_vector(0, -1);
	return (direction);
}

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
	data->input_dict = new_dict();
	data->map_list = new_list();
	data->map_height = 0;
	data->map_width = 0;
	data->color_strings = NULL;
	return (data);
}

void	mlx_data_init(t_data *data)
{
	int	endian;
	int	size_line;
	int	bits_per_pixel;

	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	textures_init(data);

	data->frame.img_ptr = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->frame.data_addr = mlx_get_data_addr(data->frame.img_ptr,
			&bits_per_pixel, &size_line, &endian);
	data->frame.bits_per_pixel = bits_per_pixel;
	data->frame.size_line = size_line;
	data->frame.endian = endian;
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
	{
		printf("node value = %s\n", data_node->value);
		data->texture_paths[_NORTH] = ft_strdup(data_node->value);
	}
	else if (ft_strcmp(data_node->key, "EA"))
	{
		printf("node value = %s\n", data_node->value);
		data->texture_paths[_EAST] = ft_strdup(data_node->value);
	}
	else if (ft_strcmp(data_node->key, "WE"))
	{
		data->texture_paths[_WEST] = ft_strdup(data_node->value);
		printf("data->texture_paths[_WEST] = %s\n", data->texture_paths[_WEST]);
	}
	else if (ft_strcmp(data_node->key, "SO"))
	{
		printf("node value = %s\n", data_node->value);
		data->texture_paths[_SOUTH] = ft_strdup(data_node->value);
	}
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
