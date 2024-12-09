CFLAGS = -Wall -Wextra -Werror
CDEBUGFLAGS = -g -fsanitize=address
COMPILER= cc $(CFLAGS)

NAME = pipex
OBJS = $(*.c=.o)
LIBFT = libft/libft.a

PIPEX_SRCS = main.c \
			utils.c

all: $(NAME)

clean : 
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

debug:
	$(COMPILER) $(CDEBUGFLAGS) $(PIPEX_SRCS) $(LIBFT) -o $(NAME)

$(NAME): $(LIBRARY)
	@make -C libft re
	@$(COMPILER) $(PIPEX_SRCS) $(LIBFT) -o $(NAME)

$(LIBRARY):
	make -C libft re