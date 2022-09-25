#include "cub3d.h"

t_bool	fill_map_list(t_string line, t_data *data)
{
	while (1)
	{
		if (!str_contains_only(line, MAP_CHARS_WN))
			return (FALSE);
		add_node(data->map_list, new_lnode(line));
		line = get_next_line(data->fd);
		if (!line)
			break ;
	}
	while (is_empty_line(data->map_list->tail->value))
		remove_node(data->map_list);
	return (TRUE);
}

void	fill_map_line(t_data *data, int index, t_string value)
{
	int	i;

	i = -1;
	data->map[index] = malloc(data->map_width + 1);
	while (++i < data->map_width && value[i] && value[i] != '\n')
		data->map[index][i] = value[i];
	while (i < data->map_width)
		data->map[index][i++] = ' ';
	data->map[index][data->map_width] = 0;
}

void	fill_map(t_string line, t_data *data)
{
	int		i;
	t_lnode	*current;

	i = -1;
	if (!fill_map_list(line, data))
		return ;
	data->map_width = get_longest_line(data->map_list);
	data->map_height = data->map_list->count;
	if (data->map_width == 0)
		return ;
	data->map = malloc(sizeof(char *) * (data->map_height + 1));
	current = data->map_list->head;
	while (++i < data->map_height)
	{
		fill_map_line(data, i, current->value);
		current = current->next;
	}
	data->map[i] = 0;
	//free_list(data->map_list);
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