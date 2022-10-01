# NAME = cub3D

# OS = $(shell uname)

# MAP = maps/map1.cub

# CC = cc

# RM = rm -rf

# FLAGS = -Wall -Wextra -Werror

# INCLUDES = -Iincludes

# # ifeq ($(OS), Linux)
# # 	MLX = mlx_linux
# # 	LINKER = -lft -lmlx -lm -lXext -lX11
# # else
# MLX = ../mlx_macos
# LINKER = -l mlx -lm -framework OpenGL -framework Appkit
# # endif

# SRCS = $(wildcard */*.c)

# SRC_OBJS = $(addprefix ,$(SRCS:.c=.o))

# all: lib $(NAME) clean run

# lib:
# 	@$(MAKE) -s -C $(MLX)

# run:
# 	./${NAME} ${MAP}

# $(NAME): $(SRC_OBJS)
# 	@echo "\n\033[0;33mCompiling..."
# 	@$(CC) $(FLAGS) -L $(MLX) $(SRC_OBJS) $(INCLUDES) $(LINKER) -o $(NAME)
# 	@echo "\033[0m"

# */%.o: */%.c
# 	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<

# clean:
# 	@echo "\033[0;31mCleaning..."
# 	@$(RM) $(SRC_OBJS)
# 	@echo "\033[0m"

# fclean: clean
# 	@echo "\033[0;31mRemoving executable..."
# 	@$(RM) $(NAME)
# 	@echo "\033[0m"

# re: fclean all

# .PHONY: all clean fclean re bonus run


NAME = cub3D

# MAP = maps/map1.cub

CC = cc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror

INCLUDES = -Iincludes

LINKER = -l mlx -framework AppKit -framework OpenGl

SRCS = $(wildcard */*.c)

SRC_OBJS = $(addprefix ,$(SRCS:.c=.o))

all: $(NAME) clean

# run:
# 	./${NAME} ${MAP}

$(NAME): $(SRC_OBJS)
	@$(CC) $(FLAGS) $(SRC_OBJS) $(INCLUDES) $(LINKER) -o $(NAME)

*/%.o: */%.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(SRC_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus run
