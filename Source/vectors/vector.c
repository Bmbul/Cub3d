/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:10:28 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:10:29 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

t_vector	s_product(t_vector vector, double multiplier)
{
	return (new_vector(vector.x * multiplier, vector.y * multiplier));
}
