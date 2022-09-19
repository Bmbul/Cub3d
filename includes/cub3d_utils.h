#ifndef CUB3D_UTILS_H
# define CUB3D_UTILS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "cub3d.h"

// get_next_line
t_string	ft_substr(const t_string s, unsigned int start, size_t len);
t_string	get_next_line(int fd);

// text_utils.c
int			text_len(t_text text);

// str_utils.c
t_string	ft_strdup(t_string const s1);
t_string	ft_strjoin(t_string const s1, t_string const s2);
size_t		ft_strlen(t_string const s);

// free.c
void		guard_free(void *data);
void		free_array(t_text arr);


// ft_split.c
t_text		ft_split(t_string const s, char c);

// printer.c

void		print_error(t_string error);
void		print_error_and_exit(t_string	error);


#endif