NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
COMPILER = clang $(CFLAGS)
LIBRARY = ar src $(NAME)
PRINTF_NAMES =	ft_printf.c\
				ft_putchar.c\
				ft_putnbr.c\
				ft_putstr.c\
				ft_putnbr_u.c\
				ft_hexadecimal.c\
				ft_putptr.c
PRINTF_OBJS = $(PRINTF_NAMES:.c=.o)
SOURCE = ./src/

all : $(NAME)

$(PRINTF_OBJS) : $(addprefix $(SOURCE), $(PRINTF_NAMES))
	@$(COMPILER) -c $(addprefix $(SOURCE), $(PRINTF_NAMES))

$(NAME) : $(PRINTF_OBJS) 
	@$(LIBRARY) $(PRINTF_OBJS)
	@mkdir obj
	@mv $(PRINTF_OBJS) obj

re : fclean all
clean :
	@rm -rf obj
fclean :
	@rm -rf obj $(NAME) a.out

.PHONY = re clean fclean all