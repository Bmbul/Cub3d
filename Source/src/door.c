/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeghiaz <syeghiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 01:11:21 by syeghiaz          #+#    #+#             */
/*   Updated: 2022/10/23 01:13:31 by syeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	update_door_map(t_data *data, int i, int j, t_text map)
{
	int		distance;

	distance = (int)(100 * sqrt(pow(data->player.pos.y
					- (j + 0.5), 2) + pow(data->player.pos.x - (i + 0.5), 2)));
	if (distance >= 200)
		map[i][j] = 1;
	else if (distance >= 180 && distance < 200)
		map[i][j] = 2;
	else if (distance >= 160 && distance < 180)
		map[i][j] = 3;
	else if (distance >= 140 && distance < 160)
		map[i][j] = 4;
	else if (distance >= 120 && distance < 140)
		map[i][j] = 5;
	else if (distance >= 100 && distance < 120)
		map[i][j] = 6;
	else if (distance >= 80 && distance < 100)
		map[i][j] = 7;
	else
		map[i][j] = 8;
}

void	update_doors_states(t_data *data)
{
	int		i;
	int		j;
	t_text	map;

	map = data->door_map;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 9)
				continue ;
			update_door_map(data, i, j, map);
		}
	}
}
