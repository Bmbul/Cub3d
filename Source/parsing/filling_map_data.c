/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:09:21 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:09:22 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_sprites_count(t_list *list)
{
	t_lnode	*current;
	int		sprites_count;
	int		i;

	sprites_count = 0;
	if (!list || !list->head)
		return (0);
	current = list->head;
	while (current)
	{
		i = -1;
		while (current->value[++i])
			if (contains("2", current->value[i]))
				sprites_count++;
		current = current->next;
	}
	return (sprites_count);
}

void	get_map_sprites(t_data *data)
{
	t_lnode	*current;
	int		col;
	int		row;
	int		index;

	index = -1;
	data->map_sprites = malloc(sizeof(t_sprite_info) * data->sprites_count);
	if (!data->map_list || !data->map_list->head)
		return ;
	current = data->map_list->head;
	row = 0;
	while (current)
	{
		col = -1;
		while (current->value[++col])
		{
			if (contains("2", current->value[col]))
				data->map_sprites[++index]
					= new_sprite_info(col, row, current->value[col]);
		}
		current = current->next;
		row++;
	}
}
