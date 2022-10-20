/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:10:25 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:10:26 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_order	new_order(int order, double dist)
{
	t_order	new;

	new.order = order;
	new.dist = dist;
	return (new);
}

void	swap_orders(t_order *first, t_order *second)
{
	t_order	temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

void	sort_order(t_order *order, int count)
{
	int	i;
	int	j;

	i = -1;
	while (++i < count - 1)
	{
		j = -1;
		while (++j < count - i - 1)
		{
			if (order[j].dist > order[j + 1].dist)
				swap_orders(order + j, order + j + 1);
		}
	}
}
