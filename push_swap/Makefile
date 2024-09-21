CFLAGS = -Wall -Wextra -Werror
COMPILER= cc $(CFLAGS)
NAME = push_swap
OBJS = $(PUSH_SWAP_OBJS)
PUSH_SWAP_OBJS = $(PUSH_SWAP_NAMES: .c=.o)
LIBRARY = ./libft/libft.a
PUSH_SWAP_MAIN = push_swap_main.c
PUSH_SWAP_NAMES = 		  main.c\
				orders.c\
				sort_alg.c\
				weight_number.c\
				text_instructions.c\
				movements_calc.c\
				pusher.c\
				error_check.c\
				utils.c
PUSH_SWAP_BONUS = checker_bonus.c\
		  read_instructions_bonus.c\

#Rules
all : $(NAME)

bonus : $(PUSH_SWAP_NAMES) $(PUSH_SWAP_BONUS)
	make -C libft re
	$(COMPILER) $(PUSH_SWAP_NAMES) $(PUSH_SWAP_BONUS) $(LIBRARY) -o checker
clean : 
	rm -rf obj

fclean : clean
	@rm -f $(NAME) checker
	@make -C libft fclean

re : fclean all

$(NAME) : $(PUSH_SWAP_NAMES) $(PUSH_SWAP_MAIN)
	@make -C libft re
	@$(COMPILER) $(PUSH_SWAP_NAMES) $(PUSH_SWAP_MAIN)  $(LIBRARY) -o $(NAME)

