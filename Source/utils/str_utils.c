#include "cub3d.h"

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

t_bool	starts_with(t_string token, char start)
{
	return (token && (token[0] == start));
}

t_bool	starts_with_string(t_string str1, t_string str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (FALSE);
	while (str1[i] && str1[i] == str2[i])
		i++;
	return (!(str1[i]) || !(str2[i]));
}

t_bool	ft_strcmp(t_string s1, t_string s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (FALSE);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (FALSE);
	}
	return (s1[i] == s2[i]);
}

t_bool	is_numeric_string(t_string str)
{
	int	i;

	if (!str)
		return (FALSE);
	i = -1;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (FALSE);
	return (TRUE);
}

t_bool	is_unsigned_char(t_string str)
{
	return (is_numeric_string(str) && !(ft_strlen(str) > 3
			|| (ft_strlen(str) == 3 && ft_strcmp(str, "256") > 0)));
}

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
