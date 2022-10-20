/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:08:54 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:08:55 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	free_node(t_node *node)
{
	if (!node)
		return ;
	free(node->key);
	free(node->value);
	node->next = NULL;
	node->prev = NULL;
	free(node);
}

static void	remove_last(t_dict *dict)
{
	t_node	*last;

	if (dict->count == 0)
		return ;
	last = dict->tail;
	if (dict->count == 1)
	{
		dict->tail = NULL;
		dict->head = NULL;
	}
	else
		dict->tail = last->prev;
	free_node(last);
	dict->count--;
}

void	free_dict(t_dict *dict)
{
	while (dict->count > 0)
		remove_last(dict);
	free(dict);
}
