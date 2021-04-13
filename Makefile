NAME		=	push_swap

SRCS		=	check_utils.c \
				ft_atoi.c \
				make_list.c \
				push_swap.c \


OBJS		=	check_utils.o \
				ft_atoi.o \
				make_list.o \
				push_swap.o \

INCLUDES	=	header.h

all: $(NAME)

$(NAME): $(OBJS)

$(OBJS): $(SRCS) $(INCLUDES)
	@gcc -Wall -Wextra -Werror $(SRCS) -o push_swap

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all
bonus: