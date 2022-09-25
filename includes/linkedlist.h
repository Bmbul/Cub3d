#ifndef LINKEDLIST_H
# define LINKEDLIST_H

typedef struct s_lnode	t_lnode;

struct s_lnode
{
	char	*value;
	t_lnode	*next;
	t_lnode	*prev;
};

typedef struct s_list
{
	t_lnode	*head;
	t_lnode	*tail;
	int		count;
}	t_list;

// linkedlist_additional_functionality.c
int		get_longest_line(t_list *list);

//	linkedlist_utils.c
void	print_list(t_list *list);
void	free_list(t_list *list);

// linkedlist.c
t_list	*new_list(void);
t_lnode	*new_lnode(char *value);
void	add_node(t_list *list, t_lnode *node);
void	free_lnode(t_lnode *node);
void	remove_node(t_list *list);

#endif