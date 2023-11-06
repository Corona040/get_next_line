NAME = get_next_line

CC = cc

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=10

LIBS = -L. -lft

SRCS_TESTER = main.c get_next_line.c get_next_line_utils.c ft_strjoinnul.c

SRCS_TEST = get_next_line.c ft_strjoinnul.c

SRCS = $(SRCS_TESTER)

RM = rm -rf

$(NAME): $(SRCS)
		   $(CC) $(CFLAGS) $^ -o $@ $(LIBS)

all: $(NAME)

tester: all

test:
	@make "SRCS=$(SRCS_TEST)"

clean: fclean

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
