CFLAGS = -Wall -Wextra -Werror
CDEBUGFLAGS = -g -fsanitize=address
COMPILER= cc $(CFLAGS)

NAME = pipex
TESTER = pipex_tester
OBJS = $(*.c=.o)
LIBFT = libft/libft.a

PIPEX_SRCS = main.c \
			utils.c \
			pipes.c

all: $(NAME)

clean :
	@rm -f $(OBJS) $(TESTER)

fclean: clean
	@rm -f $(NAME)

re: fclean all tester

debug:
	@$(COMPILER) $(CDEBUGFLAGS) $(PIPEX_SRCS) $(LIBFT) -o $(NAME)

tester:
	$(COMPILER) tester.c -o $(TESTER)

$(NAME): $(LIBRARY)
	@make -C libft re
	@$(COMPILER) $(PIPEX_SRCS) $(LIBFT) -o $(NAME)

$(LIBRARY):
	make -C libft re