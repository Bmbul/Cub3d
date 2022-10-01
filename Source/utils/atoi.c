# include "cub3d.h"

unsigned char	basic_atouc(t_string str)
{
	unsigned char	result;
	int				i;

	i = -1;
	result = 0;
	while (str[++i])
		result = result * 10 + str[i] - '0';
	return (result);
}