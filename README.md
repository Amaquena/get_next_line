# get_next_line

Get_next_line was a project that focused on memory management and file manipulation using C programming.

## Objective
I was tasked to create a function that reads a single line from a file and returns the result. The project had a few restriction and specifications; these were set to better enforce learning and understanding of the fundamentals of C.
**NOTE: A "line" is a succession of characters that ends with '\n' (ascii code: 0x0a) or End Of File (EOF)**

### General instructions
- The project contains 2 files: `get_next_line.c` & `get_next_line.h`.
- The folder [libft](https://github.com/Amaquena/libft) contains a few recreated standard C functions required for this project.
- All errors needed to be handled and the program should not quit in an unexpected manner (Segmentation faults, bus errors, double frees, etc.)
- All heap allocated memory should be freed when necessary with no meamory leaks.

**NOTE: The only libc functions allowd are `read`, `malloc` and `free`. To bypass this limitaion the funtions in the libft folder was used.**

### Specifications
1. The funtion should be prototuped as followed: `int  get_next_line(const int fd, char **line);`
    - The first parameter is the file discriptor that will be used.
    - The second parameter is the address of a pointer to a character that will be used to save the line read from the file discripter.
2. The function returns either 1, o or -1:
    - 1 if the line was read.
    - 0 if the reading is completed.
    - -1 if an error happend respectively.
3. The line should return without '\n'.
4. Calling the funtion `get_next_line` in a loop should read from the file discripter until the end of the file, regardless of the length of the line or the size of the file.
5. The header file `get_next_line.h`:
    - Should prototype the function get_next_line.
    - Have a macro defined as `BUFFER_SIZE`. This macro with store the reading buffer for the `read()` function.
6. No global variable allowed.
7. Static variables are allowed.

### Project Bonus
The project had bonus requirements that were not necessary for it's completion, but I was able to incorparate them into my project.
1. The use of a single static variable;.
2. The ability to handel multiple file discriptors.

To achieve these bonus points, I used the Linked List Data Structure and declared it as a static variable. The linked list had 2 data parts, one for the file discriptor and the second to store what was read from the reading buffer.

#### Simple usage
- Create a main.c. E.g.:
``` C
#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int		fd;
	char	*line;
	int l;
	
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((l = get_next_line(fd, &line)) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
```
- Run `make gcc`
    - The Makefile is already predine to complie and run the program.

**for a more detailed desciption of the task refer to the pdf in the resource folder.**
