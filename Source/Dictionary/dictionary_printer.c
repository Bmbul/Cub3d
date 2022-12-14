/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_printer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:08:59 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:09:00 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_env_node(t_node *node)
{
	if (node->value)
	{
		if (node->value[0])
			printf("%s=%s\n", node->key, node->value);
		else
			printf("%s=\n", node->key);
	}
}

void	print_dict(t_dict *list)
{
	for_each(list, &print_env_node);
}
