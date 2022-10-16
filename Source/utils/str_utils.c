#include "../includes/cub3d.h"

size_t	ft_strlen(t_string const s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

t_string	ft_strjoin(t_string const s1, t_string const s2)
{
	size_t	size1;
	size_t	size2;
	size_t	i;
	char	*res;

	size1 = -1;
	size2 = -1;
	i = -1;
	while (s1[++size1])
		;
	while (s2[++size2])
		;
	res = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!res)
		return (NULL);
	while (++i < size1)
		res[i] = s1[i];
	while (i - size1 < size2)
	{
		res[i] = s2[i - size1];
		i++;
	}
	res[i] = 0;
	return (res);
}

t_string	ft_strdup(t_string const s1)
{
	t_string	result;
	size_t		len;
	size_t		i;

	i = -1;
	len = ft_strlen(s1);
	result = malloc(len + 1);
	while (s1[++i])
		result[i] = s1[i];
	result[i] = 0;
	return (result);
}

t_bool	contains(t_string str, char ch)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == ch)
			return (TRUE);
	}
	return (FALSE);
}

t_bool	is_empty_line(t_string line)
{
	int	i;

	if (!line)
		return (FALSE);
	i = -1;
	while (line[++i])
		if (!contains("\n \t", line[i]))
			return (FALSE);
	return (TRUE);
}
