#include "cub3d.h"

void	guard_free(void *data)
{
	if (!data)
		return ;
	free(data);
	data = NULL;
}

void	free_array(t_text arr)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	while (arr[++i])
		guard_free(arr[i]);
	guard_free(arr);
}
