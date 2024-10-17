MLXFLAGS = -Iinclude -ldl -lglfw -pthread -lm
NAME = so_long
SO_LONG_SRC = main.c game_logic/map.c
MLX_LIBRARY = MLX42/build/libmlx42.a
COMPILER = clang $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : 
	$(COMPILER) $(SO_LONG_SRC) $(MLX_LIBRARY) $(MLXFLAGS) -o $(NAME)

fclean :
	rm -f $(NAME)

re : fclean all