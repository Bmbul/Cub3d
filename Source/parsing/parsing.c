/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeghiaz <syeghiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:09:24 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 08:34:35 by syeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	read_from_input(t_data *data)
{
	t_string	line;
	int			stop;

	stop = 0;
	line = NULL;
	while (!stop)
	{
		guard_free(line);
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
		else if (is_start_of_map(&line, &stop))
			return (fill_map(line, data));
		else
			print_error_free_and_exit(data, UNRECOGNIZED_LINE);
	}
}

void	print_map(t_data *data)
{
	int	i;

	if (!data->map)
		return ;
	i = -1;
	printf("\t\tMAP\t\t      \n");
	while (data->map[++i])
		printf("%s\n", data->map[i]);
	i = -1;
	printf("\n\tDOOR MAP\t\t      \n");
	while (data->door_map[++i])
		printf("%s\n", data->door_map[i]);
}

void	parse(t_string path, t_data *data)
{
	data->fd = open(path, O_RDONLY);
	if (data->fd == -1)
	{
		data->error_code = BAD_INPUT_FILE;
		return ;
	}
	read_from_input(data);
	print_map(data);
	if (!validate_arguments(data))
		data->error_code = BAD_ARGUMENT;
	else if (!validate_map(data))
		data->error_code = BAD_MAP;
	else
	{
		mlx_data_init(data);
		if (!data->textures->east.img_ptr || !data->textures->west.img_ptr
			|| !data->textures->north.img_ptr || !data->textures->south.img_ptr
			|| !data->floor_color || !data->ceiling_color)
			data->error_code = TEXTURE_MISSING;
	}
}
