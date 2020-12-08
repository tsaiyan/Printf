SRCS = ft_printf.c ft_putnull.c ft_parser.c display_int.c ft_utils.c display_char.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

RM = rm -f

CC = gcc -Wall -Wextra -Werror

.PHONY:		all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) ft_printf.h
	ar rc $(NAME) $?
	ranlib $(NAME)

bonus: $(OBJS) $(BNSOBJS)
	ar rc $(NAME) $?
	ranlib $(NAME)

.c.o:
	$(CC) -c $< -o $@

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} $(NAME)

re: fclean all











