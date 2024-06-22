NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
COMPILER = clang $(CFLAGS)
LIBRARY = ar src $(NAME)

PRINTF_OBJS= obj
PRINTF_NAMES =	ft_printf.o\
				ft_putchar.o\
				ft_putnbr.o\
				ft_putstr.o\
				ft_putnbr_u.o\
				ft_hexadecimal.o\
				ft_putptr.o


all : $(NAME)

%.o : src/%.c
	@mkdir -p $(PRINTF_OBJS)
	@$(COMPILER) -c $< -o $@

$(NAME) : $(PRINTF_NAMES) 
	@$(LIBRARY) $(PRINTF_NAMES)
	@mv $(PRINTF_NAMES) obj

re : fclean all
clean :
	@rm -rf $(PRINTF_NAMES) $(PRINTF_OBJS)
fclean :
	@rm -rf $(PRINTF_NAMES) $(NAME) $(PRINTF_OBJS)

.PHONY = re clean fclean all