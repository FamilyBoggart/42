CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
OBJS = $(LIBFT_NAMES) $(STRINGS) $(CONVERTERS) $(MEMORY) $(FILE_DESCRIPTOR) $(FUNCTION_ARGS)
LIBFT_NAMES= ft_isalpha.o\
		  ft_isdigit.o\
		  ft_isalnum.o\
		  ft_isascii.o\
		  ft_isprint.o\
		  ft_strncmp.o
MEMORY= ft_memset.o ft_bzero.o ft_memcpy.o ft_calloc.o ft_strdup.o ft_memmove.o ft_memchr.o ft_memcmp.o
STRINGS = ft_strlcat.o\
		  ft_strlcpy.o\
		  ft_substr.o\
		  ft_strjoin.o\
		  ft_strlen.o\
		  ft_strchr.o\
		  ft_strrchr.o\
		  ft_strnstr.o\
		  ft_strtrim.o\
		  ft_split.o
CONVERTERS = ft_toupper.o ft_tolower.o ft_atoi.o ft_itoa.o
FILE_DESCRIPTOR = ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o
FUNCTION_ARGS = ft_strmapi.o ft_striteri.o
LISTS = ft_lstnew_bonus.o ft_lstadd_front.o ft_lstsize.o ft_lstlast_bonus.o ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap_bonus.o
all: $(NAME)

#Crear la libreria
$(NAME) : $(OBJS) bonus
	ar src $(NAME) $(OBJS) $(LISTS)

# Obtener los archivos .o 
%.o : %.c
	cc $(CFLAGS) -c $< -o $@

bonus:  $(LISTS)
clean: fclean
fclean : 
	rm -f $(OBJS) $(NAME) $(LISTS)
re : fclean all

.PHONY : all clean fclean re
