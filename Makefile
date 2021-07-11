NAME = libftprintf.a

SRCS =  ft_printf.c parcer.c parcer_utils.c outputter.c \
prefixes1.c prefixes2.c outputter_type.c

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I.

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

bonus : $(NAME)

re : fclean all
