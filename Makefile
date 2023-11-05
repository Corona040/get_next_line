get_next_line: get_next_line.c
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c -o $@

all: get_next_line

clean: fclean

fclean:
	rm -rf get_next_line

re: fclean all
