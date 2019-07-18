#include "get_next_line.h"
#include <stdio.h>

int main()
{

	int		fd;
	char	*line;

	
	fd = open("large_file.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		//free(line);
	}
/*
	int fd;
	char *line;
	char *line1;
	char *line2;

	fd = open("text", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
		return (1);
	}
	if (get_next_line(fd, &line))
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	if (get_next_line(fd, &line1))
	{
		ft_putstr(line1);
		ft_putchar('\n');
	} 
	if (get_next_line(fd, &line2))
	{
		ft_putstr(line2);
		ft_putchar('\n');
	}
*/

	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return (1);
	}
}