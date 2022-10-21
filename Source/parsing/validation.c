/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeghiaz <syeghiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:09:25 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 08:07:14 by syeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

	if (data->input_dict->count < 6)
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
	validate_texture_paths(data);
	return (TRUE);
}

void	validate_texture_paths(t_data *data)
{
	int	fd;
	int	i;

	i = -1;
	while (++i < TEXTURES_COUNT)
	{
		if (has_extention(data->texture_paths[i], "xpm"))
		{
			fd = open(data->texture_paths[i], O_RDONLY);
			if (fd != -1)
				close(fd);
			else
				print_error_free_and_exit(data, BAD_ARG_FILE);
		}
		else
			print_error_free_and_exit(data, WRONG_FILE_EXT);
	}
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
	int	start_count;

	start_count = 0;
	row = -1;
	if (!data->map || !data->map_height || !data->map_width)
		return (FALSE);
	while (++row < data->map_height)
	{
		col = -1;
		while (++col < data->map_width)
		{
			if (data->map[row][col] != WALL && data->map[row][col] != EMPTY)
				if (not_surrounded_by_walls(data, row, col))
					return (FALSE);
			if (contains("NEWS", data->map[row][col]))
			{
				setup_player(data, row, col);
				start_count++;
			}
		}
	}
	return (start_count == 1);
}
