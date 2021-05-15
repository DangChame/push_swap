NAME		=	push_swap

SRCS		=	check_utils.c \
				ft_atoi.c \
				make_list.c \
				push_swap.c \
				game.c \
				game2.c \
				game3.c \
				check_utils2.c \
				ft_split.c \
				quick_sort.c \
				v4.c \
				make_list2.c \
				v4_utils.c \
				v4_utils2.c \
				v4_utils3.c \
				small_case.c \

OBJS	= ${SRCS:.c=.o}

INCLUDEs	=	header.h

all: $(NAME)

$(NAME): $(OBJS)
	gcc -Wall -Wextra -Werror $(SRCS) -o push_swap

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all
bonus:
