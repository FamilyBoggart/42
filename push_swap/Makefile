CFLAGS = -Wall -Wextra -Werror
COMPILER= cc $(CFLAGS)
NAME = push_swap
OBJS = $(PUSH_SWAP_OBJS)
PUSH_SWAP_OBJS = $(PUSH_SWAP_NAMES: .c=.o)
LIBRARY = ./libft/libft.a
PUSH_SWAP_NAMES = main.c\
				orders.c\
				sort_alg.c\
				weight_number.c\
				text_instructions.c\
				movements_calc.c\
				pusher.c\
				error_check.c\
				utils.c
#Rules
all : $(NAME)

clean : 
	rm -rf obj

fclean : clean
	@rm -f $(NAME)
	@make -C libft fclean

re : fclean all

$(NAME) : $(PUSH_SWAP_NAMES)
	@make -C libft re
	@$(COMPILER) $(PUSH_SWAP_NAMES) $(LIBRARY) -o $(NAME)

