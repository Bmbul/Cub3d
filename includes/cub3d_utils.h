#ifndef CUB3D_UTILS_H
# define CUB3D_UTILS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "cub3d.h"

// color.c
int				get_color(unsigned char t, unsigned char r,
					unsigned char g, unsigned char b);
// t_color		new_color(unsigned char red,
// 				unsigned char green, unsigned char blue);

t_color			*new_color(t_string	input_color);
void			print_color(t_color *color, t_string name);

// get_next_line
t_string		ft_substr(const t_string s, unsigned int start, size_t len);
t_string		get_next_line(int fd);

// text_utils.c
int				text_len(t_text text);

// str_utils.c
t_string		ft_strdup(t_string const s1);
t_string		ft_strjoin(t_string const s1, t_string const s2);
size_t			ft_strlen(t_string const s);
t_bool			contains(t_string str, char ch);
t_bool			is_empty_line(t_string line);
t_bool			starts_with_string(t_string str1, t_string str2);
t_bool			starts_with(t_string token, char start);
t_bool			ft_strcmp(t_string s1, t_string s2);
t_bool			is_numeric_string(t_string str);
t_bool			is_unsigned_char(t_string str);
t_bool			str_contains_only(t_string word, t_string charset);
t_bool			has_extention(t_string path, t_string extention);

// free.c
void			ft_free(void *data);
void			guard_free(char **str);
void			free_array(t_text arr);

// ft_split.c
t_text			ft_split(t_string const s, char c);

// printer.c
void			set_color(t_string color,int fd);
void			reset_color(int fd);
void			print_error(t_string error);
void			print_error_and_exit(t_string	error);

// atoi.c
unsigned char	basic_atouc(t_string str);

#endif