#include "cub3d.h"

void	fill_map(int fd, t_data *data)
{
	(void)fd;
	(void)data;
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

void	read_from_input(int fd, t_data *data)
{
	t_string	line;
	t_text		splitted;
	int			stop;

	stop = 0;
	splitted = NULL;
	while (!stop)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("the line %s\n", line);
		if (is_empty_line(line))
			continue ;
		if (is_attribute(line))
		{
			if (!fill_attribute(line, data))
				break ;
		}
		else if (is_start_of_map(line, &stop))
			(fill_map(fd, data));
	}
	guard_free(line);
}

t_bool	parse(t_string path, t_data *data)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_error_and_exit("Could not open the input file!!");
	write(1, "trying to read\n", 15);
	read_from_input(fd, data);
	print_data(data);
	if (!validate_input_paths(data))
	{
		print_error("Bad input properties");
		return (FALSE);
	}
	if (!validate_map(data))
	{
		print_error("Bad input map");
		return (FALSE);
	}
	return (TRUE);
}
