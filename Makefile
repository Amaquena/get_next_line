NAME = get_next_line.a
CFILES = *.c
OFILES = *.o

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(CFILES)
	@ar rcs $(NAME) $(OFILES)
	
all: $(NAME)
clean:
	@rm -f $(OFILES)
fclean: clean
	@rm -f $(NAME)
	@rm -f a.out
re: fclean all
	@echo "fclean / clean / all"
	@echo "_______________________________________________\n"
gcc: re
	@gcc main.c $(NAME)
	@./a.out