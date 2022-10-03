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
