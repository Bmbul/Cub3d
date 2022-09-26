NAME = cub3D

CC = cc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror

INCLUDES = -Iincludes

LINKER = -l mlx -framework AppKit -framework OpenGl

SRCS = $(wildcard */*.c)

SRC_OBJS = $(addprefix ,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(SRC_OBJS)
	@$(CC) $(FLAGS) $(SRC_OBJS) $(INCLUDES) $(LINKER) -o $(NAME)

*/%.o: */%.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(SRC_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
