# include "cub3d.h"

t_bool	validate_input_file(t_string input)
{
	int	fd;

	fd = open(input, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	close(fd);
	return (TRUE);
}
