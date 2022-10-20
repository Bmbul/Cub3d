/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:10:26 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:10:27 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_tuple	new_tuple(int x, int y)
{
	t_tuple	new;

	new.x = x;
	new.y = y;
	return (new);
}

t_tuple	vector_to_tuple(t_vector vector)
{
	return (new_tuple((int)vector.x, (int)vector.y));
}
