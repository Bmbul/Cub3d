#include "../includes/cub3d.h"

t_bool	str_contains_only(t_string word, t_string charset)
{
	int	i;
	int	j;
	int	found;

	i = -1;
	if (!word || !charset)
		return (FALSE);
	while (word[++i])
	{
		j = -1;
		found = 0;
		while (charset[++j])
		{
			if (word[i] == charset[j])
			{
				found = 1;
				break ;
			}
		}
		if (!found)
			return (FALSE);
	}
	return (TRUE);
}

t_bool	has_extention(t_string path, t_string extention)
{
	int	i;

	i = -1;
	while (path[++i] && path[i] != '.')
		;
	if (!path[i++])
		return (FALSE);
	return (ft_strcmp(path + i, extention));
}
