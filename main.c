#include "get_next_line.h"
#include <stdio.h>

int main()
{

	int		fd;
	char	*line;
	int l;

	
	fd = open("text2.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((l = get_next_line(fd, &line)) == 1)
	{
	//	printf("line: %s\t\taddress: %p\n\n", line, &line);
		printf("%s\n", line);
		free(line);
		printf("gnl return: %d\n", l);
	}
/*
	int fd;
	char *line;
	char *line1;
	char *line2;
	int l;

	fd = open("text2.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
		return (1);
	}
	if ((l = get_next_line(fd, &line)))
	{
		ft_putstr(line);
		free(line);
		printf("\ngnl return: %d\n", l);
		ft_putchar('\n');
	}
	if ((l = get_next_line(fd, &line1)))
	{
		ft_putstr(line1);
		free(line1);
		printf("\ngnl return: %d\n", l);
		ft_putchar('\n');
	} 
	if ((l = get_next_line(fd, &line2)))
	{
		ft_putstr(line2);
		free(line2);
		printf("\ngnl return: %d\n", l);
		ft_putchar('\n');
	}
*/

	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return (1);
	}
}