# include "cub3d.h"

t_vector	new_vector(float x, float y)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vector	v_sum(t_vector first, t_vector second)
{
	return (new_vector(first.x + second.x, first.y + second.y));
}

t_vector	v_diff(t_vector	first, t_vector second)
{
	return (new_vector(first.x - second.x, first.y - second.y));
}

t_vector	d_product(t_vector first, t_vector second)
{
	return (new_vector(first.x * second.x, first.y * second.y));
}

t_vector	v_inverse(t_vector vector)
{
	t_vector	new_vector;

	new_vector.x = vector.x;
	new_vector.y = -vector.y;
	return (new_vector);
}

t_vector	s_product(t_vector vector, float multiplier)
{
	return (new_vector(vector.x * multiplier, vector.y * multiplier));
}
