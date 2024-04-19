CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
OBJS = ft_memset.o ft_bzero.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_strncmp.o ft_toupper.o ft_tolower.o ft_strlen.o ft_atoi.o ft_memmove.o ft_memcpy.o ft_strchr.o ft_strrchr.o ft_strnstr.o
MEMORY= ft_calloc.o ft_strdup.o

all: $(NAME)

#Crear la libreria
$(NAME) : $(OBJS) $(MEMORY)
	ar src $(NAME) $(OBJS) $(MEMORY)

# Obtener los archivos .o 
%.o : %.c
	cc $(CFLAGS) -c $< -o $@


clean: fclean
fclean : 
	rm -f $(OBJS) $(NAME) $(MEMORY)
re : fclean all

.PHONY : all clean fclean re
