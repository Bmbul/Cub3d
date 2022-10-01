# include "cub3d.h"

t_vector	new_vector(double x, double y)
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

t_vector	s_product(t_vector vector, double multiplier)
{
	return (new_vector(vector.x * multiplier, vector.y * multiplier));
}

double	v_lenght(t_vector vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y));
}

t_tuple		new_tuple(int x, int y)
{
	t_tuple	new;

	new.x = x;
	new.y = y;
	return (new);
}

t_tuple		vector_to_tuple(t_vector vector)
{
	return (new_tuple((int)vector.x, (int)vector.y));
}
