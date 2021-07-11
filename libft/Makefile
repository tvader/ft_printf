# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvader <tvader@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 20204/17 19:28:39 by tvader            #+#    #+#              #
#    Updated: 20204/19 17:57:13 by tvader           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strdup.c ft_calloc.c\
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_nlen.c ft_uitoa.c
BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
NAME = libft.a
CC  = gcc
RM   = rm -f
CFLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		$(RM) $(OBJS) $(BOBJS)

fclean:  clean
		$(RM) $(NAME)

re:   fclean $(NAME)

bonus: $(OBJS) $(BOBJS)
		ar rcs $(NAME) $(OBJS) $(BOBJS)
		ranlib $(NAME)

.PHONY: all clean fclean re bonus
