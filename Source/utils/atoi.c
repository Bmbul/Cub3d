/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:10:08 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:10:09 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
