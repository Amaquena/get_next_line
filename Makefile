NAME = get_next_line.a
CFILES = get_next_line.c
OFILES = get_next_line.o

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(CFILES)
	@ar rc $(NAME) $(OFILES)
all: $(NAME)
clean:
	@rm -f $(OFILES)
fclean: clean
	@rm -f $(NAME)
	@rm -f a.out
re: fclean all
	@clear
	@echo "fclean / clean / all"
	@echo "_______________________________________________\n"
gcc: re
	@gcc main.c $(NAME) -L./libft -lft
	@./a.out