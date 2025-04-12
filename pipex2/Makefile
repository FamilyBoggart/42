CFLAGS = -Wall -Wextra -Werror
COMPILER = cc $(CFLAGS)
DEBUGFLAGS = -g -fsanitize=address

NAME = pipex

LIBFT = inc/libft.a
PIPEX_SRC = src/main.c\
			src/checker.c\
			src/utils.c

OBJS = $(*.c=.o)

all : $(NAME)

clean :
	@rm -f $(OBJS)

fclean :
	@rm -f $(NAME)
re : fclean all

test: $(NAME)
	@make fclean
	@make debug
	@echo "-----"
	@norminette
	@echo "-----"
	@$(COMPILER) src/tester.c $(LIBFT) -o tester
	@./tester

debug :
	@$(COMPILER) $(DEBUGFLAGS) $(PIPEX_SRC) $(LIBFT) -o $(NAME)

$(NAME) :
	@$(COMPILER) $(PIPEX_SRC) $(LIBFT) -o $(NAME)