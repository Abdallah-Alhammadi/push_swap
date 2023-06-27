# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 14:08:42 by abalhamm          #+#    #+#              #
#    Updated: 2023/06/23 18:21:33 by abalhamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_striteri.c \

SRCB =  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		
OBJS = $(SRCS:.c=.o)
OBJB = $(SRCB:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = 
NAME = libft.a

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

all: ${NAME}

clean:
	@$(RM) $(OBJS) $(OBJB)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean

bonus: $(OBJB)
	@ar -rcs $(NAME) $(OBJB)