#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector		t_vector;
typedef struct s_tuple		t_tuple;
typedef struct s_order		t_order;

struct s_vector
{
	double	x;
	double	y;
};

struct s_tuple
{
	int	x;
	int	y;
};

struct	s_order
{
	int		order;
	double	dist;
};

t_tuple		new_tuple(int x, int y);
t_tuple		vector_to_tuple(t_vector vector);
t_vector	new_vector(double x, double y);
t_vector	v_inverse(t_vector vector);
t_vector	v_sum(t_vector first, t_vector second);
t_vector	v_diff(t_vector	first, t_vector second);
t_vector	d_product(t_vector first, t_vector second);
t_vector	s_product(t_vector vector, double multiplier);
t_order		new_order(int order, double dist);
void		sort_order(t_order *order, int count);
void		swap_orders(t_order *first, t_order *second);

#endif
