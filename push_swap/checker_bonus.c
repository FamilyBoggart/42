
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

	if (argc < 2)
		return(0);
	arg = ++argv;
	system((const char *)create_instruction(arg));
	fd = open("result.txt", O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		ft_printf("%s", line);

		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}
