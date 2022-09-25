#include "cub3d.h"

void	fill_map(t_string line, t_data *data)
{
	int	i;
	int	count;
	int	max_len;

	i = 0;
	count = 0;
	while (1)
	{
		add_node(data->map_list, new_lnode(line));
		line = get_next_line(data->fd);
		if (!line)
			break ;
	}
	while (is_empty_line(data->map_list->tail->value))
		remove_node(data->map_list);
	max_len = get_longest_line(data->map_list);
	printf("max len = %d\n", max_len);
}

t_bool	fill_attribute(t_string line, t_data *data)
{
	t_text	splitted;

	line[ft_strlen(line) - 1] = 0;
	splitted = ft_split(line, ' ');
	if (text_len(splitted) != 2)
	{
		free_array(splitted);
		return (FALSE);
	}
	add(data->input_dict, new_node
		(splitted[0], splitted[1]));
	return (TRUE);
}

void	read_from_input(t_data *data)
{
	t_string	line;
	t_text		splitted;
	int			stop;

	stop = 0;
	splitted = NULL;
	while (!stop)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		if (is_empty_line(line))
			continue ;
		if (is_attribute(line))
		{
			if (!fill_attribute(line, data))
				break ;
		}
		else if (is_start_of_map(line, &stop))
			(fill_map(line, data));
	}
	guard_free(line);
}

t_bool	parse(t_string path, t_data *data)
{
	data->fd = open(path, O_RDONLY);
	if (data->fd == -1)
		print_error_and_exit("Could not open the input file!!");
	read_from_input(data);
	print_data(data);
	print_list(data->map_list);
	if (!validate_arguments(data))
	{
		print_error("Bad input arguments.");
		return (FALSE);
	}
	write(1, "finished validating arguments\n", 30);
	if (!validate_map(data))
		return (FALSE);
	mlx_data_init(data);
	if (!data->textures->east.mlx_img || !data->textures->west.mlx_img
		|| !data->textures->north.mlx_img || !data->textures->south.mlx_img
		|| !data->floor_color || !data->ceiling_color)
	{
		printf("could not validate textures\n");
		return (FALSE);
	}
	return (TRUE);
}
