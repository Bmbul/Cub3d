#include "cub3d.h"

t_color	*new_color(t_string	input_color)
{
	t_color	color;
	t_text	colors;
	int		i;

	i = -1;
	colors = ft_split(input_color, ',');
	if (text_len(colors) != 3 || !(is_unsigned_char(colors[0])
			&& is_unsigned_char(colors[1]) && is_unsigned_char(colors[2])))
		return (NULL);
	color.red = basic_atoi(colors[0]);
	color.green = basic_atoi(colors[1]);
	color.blue = basic_atoi(colors[2]);
	return (&color);
}

// t_color	new_color(unsigned char red,
// 	unsigned char green, unsigned char blue)
// {
// 	t_color	new_color;

// 	new_color.red = red;
// 	new_color.green = green;
// 	new_color.blue = blue;
// 	return (new_color);
// }

int	get_color(unsigned char t, unsigned char r,
	unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}
