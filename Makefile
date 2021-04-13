NAME		=	push_swap

SRCS		=	check_utils.c \
				ft_atoi.c \
				make_list.c \
				push_swap.c \
				game.c \
				game2.c\


OBJS	= ${SRCS:.c=.o}

INCLUDES	=	header.h

all: $(NAME)

$(NAME): $(OBJS)
	gcc -Wall -Wextra -Werror $(SRCS) -o push_swap

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all
bonus:
