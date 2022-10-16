#include "../includes/cub3d.h"

t_vector	v_inverse(t_vector vector)
{
	t_vector	new_vector;

	new_vector.x = -vector.y;
	new_vector.y = vector.x;
	return (new_vector);
}

double	v_lenght(t_vector vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y));
}
