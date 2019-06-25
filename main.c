#include "get_next_line.h"
#include "libft/libft.h"

int main()
{
	int fd;
	char *line;
	char *line1;

	fd = open("text", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
		return (1);
	}
	if (get_next_line(fd, &line))
	{
		ft_putstr(line);
		ft_putstr("\nc\n");
	}
	free(line);
	line = NULL;
	if (get_next_line(fd, &line1))
	{
		ft_putstr(line1);
		ft_putstr("\nb\n");
	}
	free(line1);
	line1 = NULL;
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return (1);
	}
}