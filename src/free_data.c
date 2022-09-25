#include "cub3d.h"

void	free_data(t_data *data)
{
	free_dict(data->input_dict);
	guard_free(data);
}
