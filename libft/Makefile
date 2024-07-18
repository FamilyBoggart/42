CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
COMPILER= cc $(CFLAGS)
LIBRARY= ar src $(NAME)
OBJS = $(LIBFT_OBJS) $(PRINTF_OBJS)
#Libft
LIBFT_OBJS = $(LIBFT_NAMES:.c=.o)
LIBFT_SOURCE = ./src/libft/
LIBFT_NAMES= ft_isalpha.c\
		  ft_isdigit.c\
		  ft_isalnum.c\
		  ft_isascii.c\
		  ft_isprint.c\
		  ft_strncmp.c\
		  ft_memset.c\
		  ft_bzero.c\
		  ft_memcpy.c\
		  ft_calloc.c\
		  ft_strdup.c\
		  ft_memmove.c\
		  ft_memchr.c\
		  ft_memcmp.c\
		  ft_strlcat.c\
		  ft_strlcpy.c\
		  ft_substr.c\
		  ft_strjoin.c\
		  ft_strlen.c\
		  ft_strchr.c\
		  ft_strrchr.c\
		  ft_strnstr.c\
		  ft_strtrim.c\
		  ft_split.c\
		  ft_toupper.c\
		  ft_tolower.c\
		  ft_atoi.c\
		  ft_itoa.c\
		  ft_putchar_fd.c\
		  ft_putstr_fd.c\
		  ft_putendl_fd.c\
		  ft_putnbr_fd.c\
		  ft_strmapi.c\
		  ft_striteri.c\
		  	ft_lstnew_bonus.c\
	  		ft_lstadd_front_bonus.c\
	  		ft_lstsize_bonus.c\
	  		ft_lstlast_bonus.c\
	  		ft_lstadd_back_bonus.c\
	  		ft_lstdelone_bonus.c\
	  		ft_lstclear_bonus.c\
	  		ft_lstiter_bonus.c\
	  		ft_lstmap_bonus.c

#Printf
PRINTF_NAMES =	ft_printf.c\
				ft_putchar.c\
				ft_putnbr.c\
				ft_putstr.c\
				ft_putnbr_u.c\
				ft_hexadecimal.c\
				ft_putptr.c
PRINTF_OBJS = $(PRINTF_NAMES:.c=.o)
PRINTF_SOURCE = ./src/printf/


#Crear la libreria


#Funtions
all: $(NAME)

bonus:  $(LISTS)
	@ar src $(NAME) $(LISTS)


# Obtener los archivos .o 
%.o : %.c
	@cc $(CFLAGS) -c $< -o $@


clean: 
	@rm -rf obj
fclean :
	@rm -rf obj  $(NAME)
re : fclean all

.PHONY : all clean fclean re

#Rules

$(LIBFT_OBJS) : $(addprefix $(LIBFT_SOURCE), $(LIBFT_NAMES))
	@$(COMPILER) -c $(addprefix $(LIBFT_SOURCE), $(LIBFT_NAMES))

$(PRINTF_OBJS) : $(addprefix $(PRINTF_SOURCE), $(PRINTF_NAMES))
	@$(COMPILER) -c $(addprefix $(PRINTF_SOURCE), $(PRINTF_NAMES))

$(NAME) : $(LIBFT_OBJS) $(PRINTF_OBJS)
	@$(LIBRARY) $(OBJS)
	@mkdir obj
	@mv $(OBJS) obj