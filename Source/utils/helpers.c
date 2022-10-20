/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:10:17 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:10:18 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	len;
	int	ext_len;

	len = ft_strlen(path);
	ext_len = ft_strlen(extention);
	if (len < ext_len)
		return (FALSE);
	return (ft_strcmp(path + len - ext_len, extention));
}
