MLXFLAGS = -Iinclude -ldl -lglfw -pthread -lm
NAME = so_long
SO_LONG_SRC = src/logic/main.c\
	src/logic/movements.c\
	src/logic/map_reader.c\
	src/textures/map_render.c\
	src/textures/delete_images.c\
	src/logic/map_checker.c\
	src/logic/map_checker_2.c\
	src/logic/collectibles.c\
	src/textures/ft_clean.c
	
MLX_LIBRARY = MLX42/build/libmlx42.a
COMPILER = clang $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

all : $(NAME)

debug: $(NAME)
	make -C libft re
	$(COMPILER) -fsanitize=address -g $(SO_LONG_SRC) $(MLX_LIBRARY) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(NAME) :
	make -C libft re
	$(COMPILER) $(SO_LONG_SRC) $(MLX_LIBRARY) $(LIBFT) $(MLXFLAGS) -o $(NAME)

fclean :
	rm -f $(NAME)

re : fclean all