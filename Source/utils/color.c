/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:10:10 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 02:18:09 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_color	*new_color(t_string	input_color)
{
	t_color	*color;
	t_text	colors;

	colors = ft_split(input_color, ',');
	if (text_len(colors) != 3 || !(is_unsigned_char(colors[0])
			&& is_unsigned_char(colors[1]) && is_unsigned_char(colors[2])))
	{
		printf("finished making color\n");
		free_array(colors);
		return (NULL);
	}
	color = malloc(sizeof(t_color));
	color->red = basic_atouc(colors[0]);
	color->green = basic_atouc(colors[1]);
	color->blue = basic_atouc(colors[2]);
	free_array(colors);
	return (color);
}

void	print_color(t_color *color, t_string name)
{
	printf("%s: r:%u g:%u b:%u", name, color->red,
		color->green, color->blue);
}

int	get_color(t_color color)
{
	return (*(int *)(unsigned char [4]){color.blue, color.green, color.red, 0});
}

unsigned int	get_img_color(t_img img, int x, int y)
{
	char	*dst;

	if (!img.img_ptr)
		return (0);
	dst = img.data_addr + (y * img.size_line + x * (img.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

unsigned int	*get_img_colors(t_img img)
{
	int				i;
	int				j;
	int				k;
	unsigned int	*ptr;

	ptr = malloc(sizeof(unsigned int) * 64 * 64);
	i = -1;
	while (++i < 64)
	{
		j = -1;
		k = 64;
		while (++j < 64 && --k > -1)
			ptr[64 * k + i] = get_img_color(img, j, i);
	}
	return (ptr);
}
