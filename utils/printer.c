# include "cub3d.h"

void	set_color(t_string color)
{
	printf("%s", color);
}

void	set_error_color(void)
{
	set_color(RED_TERM);
}

void	reset_color(void)
{
	set_color(WHITE_TERM);
}

void	print_error(t_string error)
{
	set_error_color();
	printf("%s\n", error);
	reset_color();
}

void	print_error_and_exit(t_string	error)
{
	print_error(error);
	exit(ERROR_CODE);
}
