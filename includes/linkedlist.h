#ifndef LINKEDLIST_H
# define LINKEDLIST_H

typedef struct s_node	t_node;

struct s_node
{
	char	*key;
	char	*value;
	t_node	*next;
	t_node	*prev;
	int		index;
};

typedef struct s_dict
{
	t_node	*head;
	t_node	*tail;
	int		count;
}	t_dict;

// linkedlist.c
t_dict	*new_list(void);
void	add(t_dict *list, t_node *node);
t_node	*new_node(char *key, char *value);
void	remove_with_key(t_dict *list, char *key);
void	update_with_key(t_dict *list, char *key, char *new_value);

// linkedlist_utils.c
t_node	*find_node_with_key(t_dict *list, char *key);
void	for_each(t_dict *list, void (*func)(t_node *));

// linkedlist_free.c
void	free_list(t_dict *list);
void	unset_index(t_node *node);

// linkedlist_printer.c
void	print_dict(t_dict *list);
void	print_env_node(t_node *node);

#endif
