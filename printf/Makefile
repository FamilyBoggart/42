NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
COMPILER = cc $(CFLAGS)
LIBRARY = ar src $(NAME)
PRINTF_NAMES =	ft_printf.o\
				ft_putchar.o\
				ft_putnbr.o\
				ft_putstr.o\
				ft_putnbr_u.o\
				ft_hexadecimal.o


all : $(NAME)

%.o : %.c
	$(COMPILER) -c $< -o $@

$(NAME) : $(PRINTF_NAMES) 
	$(LIBRARY) $(PRINTF_NAMES)

re : fclean all
clean :
	@rm -f $(PRINTF_NAMES)
fclean :
	@rm -f $(PRINTF_NAMES) $(NAME)

.PHONY = re clean fclean all