CFLAGS = -Wall -Wextra -Werror
COMPILER= cc $(CFLAGS)

NAME = pipex
OBJS = $(*.c=.o)
LIBFT = libft/libft.a

$(NAME): $(LIBRARY)
	$(COMPILER) main.c $(LIBFT) -o $(NAME)

$(LIBRARY):
	cd libft
	make re
	cd ..