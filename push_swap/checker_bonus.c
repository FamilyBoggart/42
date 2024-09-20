
#include "push_swap.h"

char 	*create_instruction(char **arg)
{
	 char	*str;
	int	i;

	i = 0;
	str = "./push_swap ";
	while(arg[i])
	{
		str = ft_strjoin(str, (const char *)arg[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	str = ft_strjoin(str, "> result.txt");
	return (str);
}

int	main(int argc, char *argv[])
{
	int	fd;
	char	**arg;
	char	*line;
	int	aux;
	t_list	*stack_a;

	if (argc < 2)
		return(0);
	arg = ++argv;
	system((const char *)create_instruction(arg));
	fd = open("result.txt", O_RDONLY);
	line = get_next_line(fd);
	stack_a = create_stack(check(arg, &argc, &aux), argc - 1);
	aux = 0;
	while(line)
	{
		ft_printf("%s", line);
		read_instructions(&stack_a,NULL,line);
		show(stack_a,NULL);
		free(line);
		line = get_next_line(fd);
	}
	show(stack_a, NULL);
	free(line);
	return (0);
}
