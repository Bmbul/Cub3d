/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeghiaz <syeghiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:10:11 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 06:14:23 by syeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	guard_free(t_string str)
{
	if (!(str))
		return ;
	free(str);
}

void	ft_free(void *data)
{
	if (!data)
		return ;
	free(data);
	data = NULL;
}

void	free_array(t_text arr)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	while (arr[++i])
		guard_free(arr[i]);
	free(arr);
}
