CFLAGS = -Wall -Wextra -Werror
COMPILER= cc $(CFLAGS)
NAME = push_swap
OBJS = $(PUSH_SWAP_OBJS)
PUSH_SWAP_OBJS = $(PUSH_SWAP_NAMES: .c=.o)
LIBRARY = libft.a
PUSH_SWAP_NAMES = main.c\
				push_swap.c



#Rules
all : $(NAME)
	cd libft

clean : 
	rm $(PUSH_SWAP_OBJS)

fclean : clean

re : fclean all


$(PUSH_SWAP_OBJS) : $(PUSH_SWAP_NAMES)
	$(COMPILER) -c $(PUSH_SWAP_NAMES)
$(NAME) : $(OBJS)
	$(COMPILER) $(ON)
