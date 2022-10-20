/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:09:22 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:09:23 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_bool	is_attribute(t_string str)
{
	return (starts_with_string(str, "NO") || starts_with_string(str, "SO")
		|| starts_with_string(str, "EA") || starts_with_string(str, "WE")
		|| starts_with_string(str, "F") || starts_with_string(str, "C"));
}

t_bool	is_start_of_map(t_string str, int *return_value)
{
	*return_value = contains(str, '1') * str_contains_only(str, "1 \n");
	str_contains_only(str, MAP_CHARS);
	return (*return_value);
}
