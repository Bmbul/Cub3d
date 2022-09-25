# include "cub3d.h"


static int	line_len(t_string line)
{
	int	len;

	len = -1;
	while (line[++len] && line[len] != '\n')
		;
	return (len);
}

int	get_longest_line(t_list *list)
{
	t_lnode	*current;
	int		longest_line;
	int		current_len;

	if (!list || !list->head)
		return (0);
	longest_line = line_len(list->head->value);
	current = list->head;
	while (current)
	{
		current_len = line_len(current->value);
		if (current_len > longest_line)
			longest_line = current_len;
		current = current->next;
	}
	return (longest_line);
}
