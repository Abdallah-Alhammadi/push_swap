# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 19:46:31 by abalhamm          #+#    #+#              #
#    Updated: 2023/06/23 20:33:46 by abalhamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM 		= /bin/rm -f

INCS_DIR	= ./inc
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

BUILD_DIR	= new_build

SRC_DIR		= ./srcs

SRCS =  rotate_rules.c \
		push_rules.c \
		swap_rules.c \
	    sorting.c \
		check_1.c \
		check_2.c \
		ope_select.c \
		operation_num11.c \
		operation_num23.c \
		parsing_10.c \
		parsing_22.c \
		parsing_34.c \
		parsing_45.c \
		push_swap.c \
		reverse_rotateRules.c \
		list.c

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -I $(LIBFT_DIR) -o $(NAME) 

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) -I $(INCS_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

bonus: all

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) -r $(BUILD_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all
	
.PHONY: all clean fclean re