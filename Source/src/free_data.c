/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeghiaz <syeghiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:09:49 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 07:58:59 by syeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_textures(t_data *data)
{
	free(data->textures->north.texture);
	free(data->textures->east.texture);
	free(data->textures->west.texture);
	free(data->textures->south.texture);
	mlx_destroy_image(data->mlx, data->textures->north.img_ptr);
	mlx_destroy_image(data->mlx, data->textures->east.img_ptr);
	mlx_destroy_image(data->mlx, data->textures->west.img_ptr);
	mlx_destroy_image(data->mlx, data->textures->south.img_ptr);
	mlx_destroy_image(data->mlx, data->textures->door.img_ptr);
	free(data->textures);
	free(data->a_sprites[0].sprites[0].texture);
	free(data->a_sprites[0].sprites[1].texture);
	free(data->a_sprites[0].sprites[2].texture);
	mlx_destroy_image(data->mlx, data->a_sprites[0].sprites[0].img_ptr);
	mlx_destroy_image(data->mlx, data->a_sprites[0].sprites[1].img_ptr);
	mlx_destroy_image(data->mlx, data->a_sprites[0].sprites[2].img_ptr);
	mlx_destroy_image(data->mlx, data->frame.img_ptr);
	free(data->a_sprites[0].sprites);
	free(data->a_sprites);
}

void	free_parsing_data(t_data *data)
{
	ft_free(data->texture_paths[_NORTH]);
	ft_free(data->texture_paths[_EAST]);
	ft_free(data->texture_paths[_WEST]);
	ft_free(data->texture_paths[_SOUTH]);
	free_dict(data->input_dict);
	free_list(data->map_list);
	free_array(data->map);
	ft_free(data->sprite_distance);
	ft_free(data->sprite_order);
	ft_free(data->map_sprites);
	ft_free(data->floor_color);
	ft_free(data->ceiling_color);
	ft_free(data);
}

void	full_free_data(t_data *data)
{	
	free_textures(data);
	free_parsing_data(data);
}
