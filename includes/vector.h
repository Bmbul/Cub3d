#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector		t_vector;
typedef struct s_direction	t_direction;

struct s_vector
{
	float	x;
	float	y;
};

struct s_direction
{
	t_vector	up;
	t_vector	down;
	t_vector	right;
	t_vector	left;
};

t_vector	new_vector(float x, float y);
t_vector	v_inverse(t_vector vector);
t_vector	v_sum(t_vector first, t_vector second);
t_vector	v_diff(t_vector	first, t_vector second);
t_vector	d_product(t_vector first, t_vector second);
t_vector	s_product(t_vector vector, float multiplier);

#endif