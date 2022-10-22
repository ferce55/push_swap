# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 11:13:09 by rsarri-c          #+#    #+#              #
#    Updated: 2022/10/01 17:18:33 by rsarri-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	push_swap
SRCS		=	./srcs/push_swap.c ./srcs/utils.c ./srcs/stack_utils.c ./srcs/atoi_check.c \
				./srcs/mov_utils/swap_push.c ./srcs/mov_utils/rotate.c ./srcs/mov_utils/mov_iterator.c \
				./srcs/order_list/check_len.c ./srcs/order_list/five_nums.c ./srcs/order_list/three_nums.c \
				./srcs/order_list/order_list.c ./srcs/order_list/radix_sort.c

CC			=	@gcc
CFLAGS		=	-Wall -Werror -Wextra
SANITIZE	=	-fsanitize=address
RM			=	rm -rf


OBJS		=	$(SRCS:.c=.o)
LIBFT_DIR	=	Libft
LIBFT		=	${LIBFT_DIR}/libft.a

COMP		=	$(CC) $(CFLAGS) $(SANITIZE) $(SRCS) $(LIBFT) -o $(NAME)

$(NAME):	$(OBJS)
		@echo "---------   Compiling   -----------"
		@make -sC ./Libft
		$(COMP)
		@echo "--------------DONE!!---------------"

all:		${NAME}

clean:
		@echo "-------      Cleaning       -------"
		@make -s -C $(LIBFT_DIR) clean
		@echo "-------      Cleaning       -------"
		@$(RM) $(OBJS)
		@echo "--------------DONE!!---------------"

fclean:	clean
		@echo "-------      Cleaning       -------"
		@make -s -C $(LIBFT_DIR) fclean
		@echo "-------      Cleaning       -------"
		@$(RM) $(NAME)
		@echo "--------------DONE!!---------------"

re:		fclean all

.PHONY:	all fclean clean re