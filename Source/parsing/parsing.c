#include "cub3d.h"

void	read_from_input(t_data *data)
{
	t_string	line;
	t_text		splitted;
	int			stop;

	stop = 0;
	splitted = NULL;
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
		else if (is_start_of_map(line, &stop))
			return (fill_map(line, data));
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
}

t_bool	parse(t_string path, t_data *data)
{
	data->fd = open(path, O_RDONLY);
	if (data->fd == -1)
		print_error_and_exit("Could not open the input file!!");
	read_from_input(data);
	//print_data(data);
	//print_map(data);
	if (!validate_arguments(data))
	{
		print_error("Bad input arguments.");
		return (FALSE);
	}
	if (!validate_map(data))
	{
		printf("not valid map");
		return (FALSE);
	}
	// printf("map validated\n");
	// return (FALSE);
	//int i = -1;
	//while (++i < 4)
	//	printf("texture[%d] = %s\n", i, data->texture_paths[i]);
	mlx_data_init(data);
	if (!data->textures->east->mlx_img || !data->textures->west->mlx_img
		|| !data->textures->north->mlx_img || !data->textures->south->mlx_img
		|| !data->floor_color || !data->ceiling_color)
	{
		if (!data->textures->east->mlx_img)
			printf("no east\n");
		if (!data->textures->west->mlx_img)
			printf("no west | p = %p\n", data->textures->west->mlx_img);
		if (!data->textures->north->mlx_img)
			printf("no north\n");
		if (!data->textures->south->mlx_img)
			printf("no south\n");
		printf("could not validate textures\n");
		return (FALSE);
	}
	return (TRUE);
}
