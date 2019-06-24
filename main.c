#include "get_next_line.h"
#include "libft/libft.h"

int main()
{
	int fd;
	char *line;

	fd = open("text", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
		return (1);
	}
	if (get_next_line(fd, &line))
	{
		ft_putstr(line);
	}	
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return (1);
	}
}