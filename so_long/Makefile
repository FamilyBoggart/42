MLXFLAGS = -Iinclude -ldl -lglfw -pthread -lm
NAME = so_long
SO_LONG_SRC = src/logic/main.c\
	src/logic/movements.c\
	src/logic/map_reader.c\
	src/logic/map_render.c
	
MLX_LIBRARY = MLX42/build/libmlx42.a
COMPILER = clang $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

all : $(NAME)

$(NAME) :
	make -C libft re
	$(COMPILER) $(SO_LONG_SRC) $(MLX_LIBRARY) $(LIBFT) $(MLXFLAGS) -o $(NAME)

fclean :
	rm -f $(NAME)

re : fclean all