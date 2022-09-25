# include "cub3d.h"

t_list	*new_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->count = 0;
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

t_lnode	*new_lnode(t_string value)
{
	t_lnode	*node;

	node = malloc(sizeof(t_lnode));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_node(t_list *list, t_lnode *node)
{
	if (!node || !list)
		return ;
	if (!list->head)
		list->head = node;
	else
	{
		list->tail->next = node;
		node->prev = list->tail;
	}
	list->tail = node;
	list->count++;
}

void	free_lnode(t_lnode *node)
{
	guard_free(node->value);
	guard_free(node);
}

void	remove_node(t_list *list)
{
	t_lnode	*new_last;

	if (!list || !list->head)
		return ;
	if (list->count == 1)
	{
		free_lnode(list->head);
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		new_last = list->tail->prev;
		free_lnode(list->tail);
		list->tail = new_last;
		list->tail->next = NULL;
	}
	list->count--;
}
