/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:09:12 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:09:13 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

typedef struct s_lnode	t_lnode;
typedef struct s_list	t_list;

struct s_lnode
{
	char	*value;
	t_lnode	*next;
	t_lnode	*prev;
};

struct s_list
{
	t_lnode	*head;
	t_lnode	*tail;
	int		count;
};

// linkedlist_additional_functionality.c
int		get_longest_line(t_list *list);

//	linkedlist_utils.c
void	print_list(t_list *list);
void	free_list(t_list *list);
void	free_list_nodes(t_list *list);

// linkedlist.c
t_list	*new_list(void);
t_lnode	*new_lnode(char *value);
void	add_node(t_list *list, t_lnode *node);
void	free_lnode(t_lnode *node);
void	remove_node(t_list *list);

#endif
