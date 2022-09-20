# include "cub3d.h"

void	read_from_input(int fd, t_data *data)
{

}

t_bool	parse(t_string path, t_data *data)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_error_and_exit("Could not open the input file!!");
	read_from_input(fd, data);
	if (!validate_input_paths(data) || !validate_map(data))
		return (FALSE);
	return (TRUE);
}
