get_next_line: get_next_line.c
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=10 get_next_line.c -o $@ -L. -lft
