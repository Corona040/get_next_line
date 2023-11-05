NAME = get_next_line

CC = cc

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=10

SRCS = main.c get_next_line.c get_next_line_utils.c

RM = rm -rf

$(NAME): $(SRCS)
		   $(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

clean: fclean

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
