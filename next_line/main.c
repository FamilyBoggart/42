#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	

	return (0);
}
