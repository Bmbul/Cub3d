NAME = cub3D

OS = $(shell uname)

CC = cc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror

INCLUDES = includes

ifeq ($(OS), Linux)
	MLX = ../mlx_linux
	LINKER = -lmlx -lm -lXext -lX11
else
	MLX = ../mlx_macos
	LINKER = -l mlx -lm -framework OpenGL -framework Appkit
endif

SRCS = $(wildcard */*.c)

SRC_OBJS = $(addprefix ,$(SRCS:.c=.o))

all: $(NAME) clean

$(NAME): $(SRC_OBJS)
	@$(CC) $(FLAGS) -L $(MLX) $(SRC_OBJS) -I$(INCLUDES) $(LINKER) -o $(NAME)

*/%.o: */%.c
	@$(CC) $(FLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(SRC_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
