#include "cub3d.h"

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

static void	remove_last(t_dict *list)
{
	t_node	*last;

	if (list->count == 0)
		return ;
	last = list->tail;
	if (list->count == 1)
	{
		list->tail = NULL;
		list->head = NULL;
	}
	else
		list->tail = last->prev;
	free_node(last);
	list->count--;
}

void	free_list(t_dict *list)
{
	while (list->count > 0)
		remove_last(list);
	free(list);
}
