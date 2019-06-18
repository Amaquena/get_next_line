NAME = get_next_line.a
CFILES = get_next_line.c
OFILES = get_next_line.o

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(CFILES)
	@ar rcs $(NAME) $(OFILES)
	@ranlib $(NAME)

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
	@gcc $(CFILES) $(NAME)
	@./a.out
