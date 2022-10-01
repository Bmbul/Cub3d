#include "cub3d.h"

t_color	*new_color(t_string	input_color)
{
	t_color	*color;
	t_text	colors;
	int		i;

	i = -1;
	colors = ft_split(input_color, ',');
	// while (colors[++i])
	// {
	// 	printf("colors[%d] = %s ", i, colors[i]);
	// }
	// printf("\n");
	// i = -1;
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
	return (color);
}

void	print_color(t_color *color, t_string name)
{
	printf("%s: r:%u g:%u b:%u", name, color->red,
		color->green, color->blue);
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
