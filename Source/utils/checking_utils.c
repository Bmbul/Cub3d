/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:10:09 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:10:10 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
