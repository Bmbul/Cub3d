# include "cub3d.h"

int	text_len(t_text text)
{
	int	len;

	len = -1;
	if (!text)
		return (0);
	while (text[++len])
		;
	return (len);
}
