# include "cub3d.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		print_error_and_exit("Could not create Game Data");
	return (data);
}
