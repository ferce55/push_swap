/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:56:48 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/07/27 14:48:36 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../Libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_info
{
	int	max;
	int	min;
	int	len;
}	t_info;

void	ft_error(t_stack **stack, t_info *info);
t_stack	*ft_stack_new(int content);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_free(t_stack **stack, t_info *info);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
int		ft_atoi_check(const char *str, t_stack **stack, t_info **info);
void	do_move(char *c, t_stack **stack_a, t_stack **stack_b, int count);
void	iter_swap(char *c, t_stack **stack_a, t_stack **stack_b);
void	iter_rotate(char *c, t_stack **stack_a, t_stack **stack_b);
void	do_swap(t_stack **stack);
void	do_swap_twice(t_stack **stack_a, t_stack **stack_b);
void	do_push(t_stack **stack_src, t_stack **stack_dst);
void	do_rotate(t_stack **stack);
void	do_rotate_twice(t_stack **stack_a, t_stack **stack_b);
void	do_rev_rotate(t_stack **stack);
void	do_rev_rotate_twice(t_stack **stack_a, t_stack **stack_b);
void	check_len(t_stack **stack_a, t_stack **stack_b, t_info **info);
int		check_order(t_stack **stack_a);
void	three_nums_case(t_stack **stack_a, t_stack **stack_b);
void	four_nums_case(t_stack **stack_a, t_stack **stack_b, t_info **info);
void	five_nums_case(t_stack **stack_a, t_stack **stack_b, t_info **info);
void	check_max_min(t_stack **stack_a, t_stack **stack_b, t_info **info);
void	order_list(t_stack **stack_a, t_stack **stack_b, t_info **info);
void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_info **info);

//borrar!!!!!!!
void	show_actual_state(t_stack *stack, char a);

#endif