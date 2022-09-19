#include "cub3d.h"

size_t	ft_strlcpy(char *dst, t_string const src, size_t destsize)
{
	size_t	i;

	if (destsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < (destsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

char	*ft_substr(t_string const s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	size_t			total_len;

	i = 0;
	if (start > ft_strlen(s))
		total_len = 0;
	else if (ft_strlen(s) - start > len)
		total_len = len;
	else
		total_len = ft_strlen(s) - start;
	str = (char *)malloc(total_len + 1);
	if (!str)
		return (NULL);
	if (str)
		ft_strlcpy(str, s + start, total_len + 1);
	return (str);
}
