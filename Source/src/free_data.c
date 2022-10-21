/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:09:49 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 02:37:46 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_data(t_data *data)
{
	free_dict(data->input_dict);
	free_list(data->map_list);
	free_array(data->map);
	free(data->textures->north.texture);
	free(data->textures->east.texture);
	free(data->textures->west.texture);
	free(data->textures->south.texture);
	mlx_destroy_image(data->mlx, data->textures->north.img_ptr);
	mlx_destroy_image(data->mlx, data->textures->east.img_ptr);
	mlx_destroy_image(data->mlx, data->textures->west.img_ptr);
	mlx_destroy_image(data->mlx, data->textures->south.img_ptr);
	free(data->textures);
	free(data->a_sprites[0].sprites[0].texture);
	free(data->a_sprites[0].sprites[1].texture);
	free(data->a_sprites[0].sprites[2].texture);
	mlx_destroy_image(data->mlx, data->a_sprites[0].sprites[0].img_ptr);
	mlx_destroy_image(data->mlx, data->a_sprites[0].sprites[1].img_ptr);
	mlx_destroy_image(data->mlx, data->a_sprites[0].sprites[2].img_ptr);
	free(data->a_sprites[0].sprites);
	free(data->a_sprites);
	free(data->sprite_distance);
	free(data->sprite_order);
	mlx_destroy_image(data->mlx, data->frame.img_ptr);
	free(data->map_sprites);
	free(data->floor_color);
	free(data->ceiling_color);
	free(data->texture_paths[_NORTH]);
	free(data->texture_paths[_EAST]);
	free(data->texture_paths[_WEST]);
	free(data->texture_paths[_SOUTH]);
	free(data);
}
