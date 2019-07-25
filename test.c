#include "libft/libft.h"
#include <stdio.h>

int main ()
{
	char str[] = "Hello you little person.";
	char *temp = ft_strdup(str + 5);
	printf("temp: %s\nstr: %s\n", temp, str);
	printf("str: %s\t\taddress: %p\n", str, &str);
	printf("temp: %s\t\taddress: %p\n", temp, &temp);
    return (0);
}