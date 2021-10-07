# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/03 12:01:38 by rsarri-c          #+#    #+#              #
#    Updated: 2021/10/03 19:50:42 by rsarri-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
SRCS		=	./srcs/push_swap.c ./srcs/utils.c\

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

LIBFT_DIR	=	libft/
LIBFT		=	$(LIBFT_DIR)libft.a
OBJS		=	$(SRCS:.c=.o)

$(NAME):	$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

all: $(NAME)
clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	

.PHONY: