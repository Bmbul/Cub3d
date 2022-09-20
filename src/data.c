# include "cub3d.h"

t_data	*init_data(void)
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
	return (data);
}

t_bool	add_to_data(t_node *data_node, t_data *data)
{
	if (ft_strcmp(data_node->key, "NO"))
		data->textures->north = data_node->value;
	else if (ft_strcmp(data_node->key, "SO"))
		data->textures->south = data_node->value;
	else if (ft_strcmp(data_node->key, "WE"))
		data->textures->west = data_node->value;
	else if (ft_strcmp(data_node->key, "EA"))
		data->textures->east = data_node->value;
	else if (ft_strcmp(data_node->key, "F"))
		data->floor_color = new_color(data_node->value);
	else if (ft_strcmp(data_node->key, "C"))
		data->ceiling_color = new_color(data_node->value);
	else
		return (FALSE);
	return (TRUE);
}
