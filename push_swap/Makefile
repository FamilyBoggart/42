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



#Rules
all : $(NAME)

clean : 
	rm *.o 

fclean :
	rm -rf *.o libft/libft.a libft/obj obj $(NAME)

re : fclean all


$(PUSH_SWAP_OBJS) : $(PUSH_SWAP_NAMES)
	$(COMPILER) -c $(PUSH_SWAP_NAMES)
$(NAME) : $(OBJS)
	$(MAKE) -C libft re
	$(COMPILER) $(OBJS) $(LIBRARY) -o $(NAME)
	mkdir obj
	mv *.o obj
