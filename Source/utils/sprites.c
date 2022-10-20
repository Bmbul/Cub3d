/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:10:19 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:10:20 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite_info	new_sprite_info(int x, int y, int texture)
{
	t_sprite_info	sprite;

	sprite.pos = new_vector(y + 0.5, x + 0.5);
	sprite.texture = texture;
	return (sprite);
}

unsigned int	get_animated_sprite_color(char letter,
	t_data *data, int x, int y)
{
	unsigned int		color;
	t_animated_sprite	current_sprite;

	if (letter == ENEMY)
	{
		current_sprite = data->a_sprites[ENEMY_INDEX];
		color = get_img_color(current_sprite.sprites
			[current_sprite.current_index], x, y);
	}
	else
		color = 0;
	return (color);
}
