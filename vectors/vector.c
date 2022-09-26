# include "cub3d.h"

t_vector	new_vector(int x, int y)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vector	v_sum(t_vector first, t_vector second)
{
	t_vector	sum;

	sum.x = first.x + second.x;
	sum.y = first.y + second.y;
	return (sum);
}

t_vector	v_diff(t_vector	first, t_vector second)
{
	t_vector	diff;

	diff.x = first.x - second.x;
	diff.y = first.y - second.y;
	return (diff);
}

t_vector	d_product(t_vector first, t_vector second)
{
	t_vector	product;

	product.x = first.x + second.x;
	product.y = first.y + product.y;
	return (product);
}
