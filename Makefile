get_next_line: get_next_line.c
	cc -D BUFFER_SIZE=10 get_next_line.c -o $@ -L. -lft
