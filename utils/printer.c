# include "cub3d.h"

void	set_color(t_string color, int fd)
{
	write(fd, color, ft_strlen(color));
}

void	set_error_color(void)
{
	set_color(RED_TERM, 2);
}

void	reset_color(int fd)
{
	set_color(WHITE_TERM, fd);
}

void	print_error(t_string error)
{
	set_error_color();
	write(2, "ERROR! ", 7);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	reset_color(2);
}

void	print_error_and_exit(t_string	error)
{
	print_error(error);
	exit(ERROR_CODE);
}
