CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
OBJS = $(LIBFT_NAMES)
COMPILER= cc $(CFLAGS) 
LIBFT_NAMES= ft_isalpha.o\
		  ft_isdigit.o\
		  ft_isalnum.o\
		  ft_isascii.o\
		  ft_isprint.o\
		  ft_strncmp.o\
		  ft_memset.o\
		  ft_bzero.o\
		  ft_memcpy.o\
		  ft_calloc.o\
		  ft_strdup.o\
		  ft_memmove.o\
		  ft_memchr.o\
		  ft_memcmp.o\
		  ft_strlcat.o\
		  ft_strlcpy.o\
		  ft_substr.o\
		  ft_strjoin.o\
		  ft_strlen.o\
		  ft_strchr.o\
		  ft_strrchr.o\
		  ft_strnstr.o\
		  ft_strtrim.o\
		  ft_split.o\
		  ft_toupper.o\
		  ft_tolower.o\
		  ft_atoi.o\
		  ft_itoa.o\
		  ft_putchar_fd.o\
		  ft_putstr_fd.o\
		  ft_putendl_fd.o\
		  ft_putnbr_fd.o\
		  ft_strmapi.o\
		  ft_striteri.o\

LISTS=ft_lstnew_bonus.o\
	  ft_lstadd_front_bonus.o\
	  ft_lstsize_bonus.o\
	  ft_lstlast_bonus.o\
	  ft_lstadd_back_bonus.o\
	  ft_lstdelone_bonus.o\
	  ft_lstclear_bonus.o\
	  ft_lstiter_bonus.o\
	  ft_lstmap_bonus.o

#Crear la libreria
LIBRARY= ar src $(NAME)

#Funtions
all: $(NAME)

bonus:  $(LISTS)
	@ar src $(NAME) $(LISTS)

$(NAME) : $(OBJS)
	@$(LIBRARY) $(OBJS)

# Obtener los archivos .o 
%.o : %.c
	@cc $(CFLAGS) -c $< -o $@


clean: 
	@rm -f $(OBJS) $(LISTS)
fclean :
	@rm -f $(OBJS) $(LISTS) $(NAME)
re : fclean all

.PHONY : all clean fclean re
