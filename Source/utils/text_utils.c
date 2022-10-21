/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:10:22 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:10:23 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
