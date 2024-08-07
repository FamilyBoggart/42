CFLAGS = -Wall -Wextra -Werror
COMPILER= cc $(CFLAGS)
NAME = push_swap
OBJS = $(PUSH_SWAP_OBJS)
PUSH_SWAP_OBJS = $(PUSH_SWAP_NAMES: .c=.o)
LIBRARY = ./libft/libft.a
PUSH_SWAP_NAMES = main.c\
				push_swap.c



#Rules
all : $(NAME)

clean : 
	rm *.o 

fclean :
	rm -rf *.o libft/libft.a libft/obj $(NAME)

re : fclean all


$(PUSH_SWAP_OBJS) : $(PUSH_SWAP_NAMES)
	$(COMPILER) -c $(PUSH_SWAP_NAMES)
$(NAME) : $(OBJS)
	$(MAKE) -C libft re
	$(COMPILER) $(OBJS) $(LIBRARY) -o $(NAME)
